/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    P2P_Server_app.c
  * @author  MCD Application Team
  * @brief   P2P_Server_app application definition.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_common.h"
#include "log_module.h"
#include "app_ble.h"
#include "ll_sys_if.h"
#include "dbg_trace.h"
#include "p2p_server_app.h"
#include "p2p_server.h"
#include "stm32_rtos.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "app_bsp.h"
#include "stm32_timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
 typedef struct{
    uint8_t             Device_Led_Selection;
    uint8_t             Led1;
 }P2P_LedCharValue_t;

 typedef struct{
    uint8_t             Device_Button_Selection;
    uint8_t             ButtonStatus;
 }P2P_ButtonCharValue_t;
/* USER CODE END PTD */

typedef enum
{
  Switch_c_NOTIFICATION_OFF,
  Switch_c_NOTIFICATION_ON,
  /* USER CODE BEGIN Service1_APP_SendInformation_t */

  /* USER CODE END Service1_APP_SendInformation_t */
  P2P_SERVER_APP_SENDINFORMATION_LAST
} P2P_SERVER_APP_SendInformation_t;

typedef struct
{
  P2P_SERVER_APP_SendInformation_t     Switch_c_Notification_Status;
  /* USER CODE BEGIN Service1_APP_Context_t */
  P2P_LedCharValue_t              LedControl;
  P2P_ButtonCharValue_t           ButtonControl;
  /* USER CODE END Service1_APP_Context_t */
  uint16_t              ConnectionHandle;
} P2P_SERVER_APP_Context_t;

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN PD */
#ifndef CFG_SCH_PRIO_0
#define CFG_SCH_PRIO_0    0    /* 默认最低优先级 */
#endif

#define CFG_TASK_SEND_CUSTOM_ID    13U
/* USER CODE END PD */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Private macros ------------------------------------------------------------*/
/* USER CODE BEGIN PM */
UTIL_TIMER_Object_t BleNotifyTimer;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
static P2P_SERVER_APP_Context_t P2P_SERVER_APP_Context;

uint8_t a_P2P_SERVER_UpdateCharData[247];

/* USER CODE BEGIN PV */
volatile uint8_t tx_ready = 1;   // 全局标志，1=可发送，0=忙碌
volatile uint8_t ble_notify_enabled = 0;

static const int16_t sample_input[6][24] = {
    {1689,149,84,52,56,56,712,790,43,22,174,1307,63,183,967,1012,369,145,486,351,236,54,175,56},
    {1400,136,79,50,53,53,644,737,44,22,163,1298,57,167,904,952,353,137,460,337,227,48,163,49},
    {1190,112,64,45,48,52,642,715,41,20,155,1139,52,150,835,904,338,132,436,320,219,43,152,43},
    {1091,105,63,43,48,48,638,662,40,19,143,1314,51,141,782,878,331,132,424,309,218,43,149,43},
    {970,92,58,41,45,46,637,684,39,18,155,1276,48,138,810,872,327,128,424,314,216,41,145,42},
    {737,78,51,38,42,43,626,715,38,17,158,1323,48,134,812,854,324,129,423,312,216,41,144,40}
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
static void P2P_SERVER_Switch_c_SendNotification(void);

/* USER CODE BEGIN PFP */
static void P2P_SERVER_APP_LED_BUTTON_context_Init(void);
/* USER CODE END PFP */

/* Functions Definition ------------------------------------------------------*/
void P2P_SERVER_Notification(P2P_SERVER_NotificationEvt_t *p_Notification)
{
  /* USER CODE BEGIN Service1_Notification_1 */

  /* USER CODE END Service1_Notification_1 */
  switch(p_Notification->EvtOpcode)
  {
    /* USER CODE BEGIN Service1_Notification_Service1_EvtOpcode */

    /* USER CODE END Service1_Notification_Service1_EvtOpcode */

    case P2P_SERVER_LED_C_READ_EVT:
      /* USER CODE BEGIN Service1Char1_READ_EVT */

      /* USER CODE END Service1Char1_READ_EVT */
      break;

    case P2P_SERVER_LED_C_WRITE_NO_RESP_EVT:
      /* USER CODE BEGIN Service1Char1_WRITE_NO_RESP_EVT */
      if(p_Notification->DataTransfered.p_Payload[1] == 0x01)
      {
      #if (CFG_LED_SUPPORTED == 1)
        BSP_LED_On(LED_BLUE);
      #endif
        LOG_INFO_APP("-- P2P APPLICATION SERVER : LED1 ON\n");
        P2P_SERVER_APP_Context.LedControl.Led1 = 0x01; /* LED1 ON */
      }
      if(p_Notification->DataTransfered.p_Payload[1] == 0x00)
      {
      #if (CFG_LED_SUPPORTED == 1)
        BSP_LED_Off(LED_BLUE);
      #endif
        LOG_INFO_APP("-- P2P APPLICATION SERVER : LED1 OFF\n");
      }
      P2P_SERVER_APP_Context.LedControl.Led1 = 0x00; /* LED1 OFF */
      /* USER CODE END Service1Char1_WRITE_NO_RESP_EVT */
      break;

    case P2P_SERVER_SWITCH_C_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN Service1Char2_NOTIFY_ENABLED_EVT */
      P2P_SERVER_APP_Context.Switch_c_Notification_Status = Switch_c_NOTIFICATION_ON;
      LOG_INFO_APP("-- P2P APPLICATION SERVER : NOTIFICATION ENABLED\n");
      LOG_INFO_APP(" \n\r");
      tx_ready = 1;   // ✅ 确保初始为可用
      UTIL_SEQ_ResumeTask(1U << CFG_TASK_SEND_CUSTOM_ID);
      UTIL_SEQ_SetTask(1U << CFG_TASK_SEND_CUSTOM_ID, 0);  // 启动发送
      /* USER CODE END Service1Char2_NOTIFY_ENABLED_EVT */
      break;

    case P2P_SERVER_SWITCH_C_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN Service1Char2_NOTIFY_DISABLED_EVT */
      P2P_SERVER_APP_Context.Switch_c_Notification_Status = Switch_c_NOTIFICATION_OFF;
      LOG_INFO_APP("-- P2P APPLICATION SERVER : NOTIFICATION DISABLED\n");
      tx_ready = 1;   // ✅ 强制恢复
      HAL_PWR_EnterSTANDBYMode();
      // UTIL_TIMER_Stop(&BleNotifyTimer);       // ✅ 手机关闭 Notify 时停止定时器
      // UTIL_SEQ_PauseTask(1U << CFG_TASK_SEND_CUSTOM_ID);
      /* USER CODE END Service1Char2_NOTIFY_DISABLED_EVT */
      break;

    default:
      /* USER CODE BEGIN Service1_Notification_default */

      /* USER CODE END Service1_Notification_default */
      break;
  }
  /* USER CODE BEGIN Service1_Notification_2 */

  /* USER CODE END Service1_Notification_2 */
  return;
}

void P2P_SERVER_APP_EvtRx(P2P_SERVER_APP_ConnHandleNotEvt_t *p_Notification)
{
  /* USER CODE BEGIN Service1_APP_EvtRx_1 */

  /* USER CODE END Service1_APP_EvtRx_1 */

  switch(p_Notification->EvtOpcode)
  {
    /* USER CODE BEGIN Service1_APP_EvtRx_Service1_EvtOpcode */

    /* USER CODE END Service1_APP_EvtRx_Service1_EvtOpcode */
    case P2P_SERVER_CONN_HANDLE_EVT :
      /* USER CODE BEGIN Service1_APP_CONN_HANDLE_EVT */

      /* USER CODE END Service1_APP_CONN_HANDLE_EVT */
      break;

    case P2P_SERVER_DISCON_HANDLE_EVT :
      /* USER CODE BEGIN Service1_APP_DISCON_HANDLE_EVT */
      P2P_SERVER_APP_LED_BUTTON_context_Init();
      P2P_SERVER_APP_Context.Switch_c_Notification_Status = Switch_c_NOTIFICATION_OFF;
      tx_ready = 1;   // ✅ 强制恢复
      LOG_INFO_APP("-- P2P APPLICATION SERVER : DISCONNECTED, STOP NOTIFY TASK\n");
      /* USER CODE END Service1_APP_DISCON_HANDLE_EVT */
      break;

    default:
      /* USER CODE BEGIN Service1_APP_EvtRx_default */

      /* USER CODE END Service1_APP_EvtRx_default */
      break;
  }

  /* USER CODE BEGIN Service1_APP_EvtRx_2 */

  /* USER CODE END Service1_APP_EvtRx_2 */

  return;
}

void P2P_SERVER_APP_Init(void)
{
  UNUSED(P2P_SERVER_APP_Context);
  P2P_SERVER_Init();

  /* USER CODE BEGIN Service1_APP_Init */
  // UTIL_SEQ_RegTask( 1U << CFG_TASK_SEND_NOTIF_ID, UTIL_SEQ_RFU, P2P_SERVER_Switch_c_SendNotification);
  // /* 注册通知发送任务 */
  UTIL_SEQ_RegTask( 1U << CFG_TASK_SEND_CUSTOM_ID, UTIL_SEQ_RFU, BLE_SendSampleInput);

  // UTIL_TIMER_Create(&BleNotifyTimer, 1000, UTIL_TIMER_PERIODIC, Send_Test_Data, 0);


  /* 启动一次任务，之后在任务内自己重新触发 */
  // UTIL_SEQ_SetTask( 1U << CFG_TASK_SEND_NOTIF_ID, CFG_SCH_PRIO_0);
  /**
  * Initialize LedButton Service
  */
  P2P_SERVER_APP_Context.Switch_c_Notification_Status= Switch_c_NOTIFICATION_OFF;
  P2P_SERVER_APP_LED_BUTTON_context_Init();
  /* USER CODE END Service1_APP_Init */
  return;
}

/* USER CODE BEGIN FD */

/* USER CODE END FD */

/*************************************************************
 *
 * LOCAL FUNCTIONS
 *
 *************************************************************/
__USED void P2P_SERVER_Switch_c_SendNotification(void) /* Property Notification */
{
  P2P_SERVER_APP_SendInformation_t notification_on_off = Switch_c_NOTIFICATION_OFF;
  P2P_SERVER_Data_t p2p_server_notification_data;

  p2p_server_notification_data.p_Payload = (uint8_t*)a_P2P_SERVER_UpdateCharData;
  p2p_server_notification_data.Length = 0;

  /* USER CODE BEGIN Service1Char2_NS_1 */
  if(P2P_SERVER_APP_Context.ButtonControl.ButtonStatus == 0x00)
  {
    P2P_SERVER_APP_Context.ButtonControl.ButtonStatus = 0x01;
  }
  else
  {
    P2P_SERVER_APP_Context.ButtonControl.ButtonStatus = 0x00;
  }
  a_P2P_SERVER_UpdateCharData[0] = 0x01; /* Device Led selection */
  a_P2P_SERVER_UpdateCharData[1] = P2P_SERVER_APP_Context.ButtonControl.ButtonStatus;
  /* Update notification data length */
  p2p_server_notification_data.Length = (p2p_server_notification_data.Length) + 2;

  if(P2P_SERVER_APP_Context.Switch_c_Notification_Status == Switch_c_NOTIFICATION_ON)
  {
    LOG_INFO_APP("-- P2P APPLICATION SERVER : INFORM CLIENT BUTTON 1 PUSHED\n");
    notification_on_off = Switch_c_NOTIFICATION_ON;
  }
  else
  {
    LOG_INFO_APP("-- P2P APPLICATION SERVER : CAN'T INFORM CLIENT - NOTIFICATION DISABLED\n");
  }
  /* USER CODE END Service1Char2_NS_1 */

  if (notification_on_off != Switch_c_NOTIFICATION_OFF)
  {
    P2P_SERVER_UpdateValue(P2P_SERVER_SWITCH_C, &p2p_server_notification_data);
  }

  /* USER CODE BEGIN Service1Char2_NS_Last */

  /* USER CODE END Service1Char2_NS_Last */

  return;
}

/* USER CODE BEGIN FD_LOCAL_FUNCTIONS */
static void P2P_SERVER_APP_LED_BUTTON_context_Init(void)
{
  #if (CFG_LED_SUPPORTED == 1)
  BSP_LED_Off(LED_BLUE);
  #endif
  P2P_SERVER_APP_Context.LedControl.Device_Led_Selection=0x01;        /* select device 01 */
  P2P_SERVER_APP_Context.LedControl.Led1=0x00;                        /* led OFF */
  P2P_SERVER_APP_Context.ButtonControl.Device_Button_Selection=0x01;  /* select device 01 */
  P2P_SERVER_APP_Context.ButtonControl.ButtonStatus=0x00;

  return;
}

void P2P_SERVER_SendCustomMessage(const char *msg)
{
    if (P2P_SERVER_APP_Context.Switch_c_Notification_Status == Switch_c_NOTIFICATION_ON)
    {
        P2P_SERVER_Data_t data;
        data.p_Payload = (uint8_t *)msg;
        data.Length = strlen(msg);

        tBleStatus ret = P2P_SERVER_UpdateValue(P2P_SERVER_SWITCH_C, &data);
        if (ret == BLE_STATUS_SUCCESS)
        {
            LOG_INFO_APP("✅ Notify sent: %s\r\n", msg);
        }
        else
        {
            LOG_INFO_APP("❌ Notify failed: 0x%02X\r\n", ret);
        }
    }
    else
    {
        LOG_INFO_APP("⚠️ Notify not enabled yet (phone must subscribe)\r\n");
    }
}

void Send_Test_Data(void)
{

    // if (!tx_ready ||
    // P2P_SERVER_APP_Context.Switch_c_Notification_Status != Switch_c_NOTIFICATION_ON)
    // {
    //     return; // TX繁忙或未启用Notify，不发
    // }
    // tx_ready = 0; // 发前置忙状态
    
    /* 准备要发送的字符串 */
    static uint32_t lastTick = 0;       // 上次发送时间戳
    const char msg[] = "test,123456";

    // if (!tx_ready || i >= 5)
    // {
    //     UTIL_SEQ_SetTask(1U << CFG_TASK_SEND_CUSTOM_ID, 0);
    //     LOG_DEBUG_APP("⚠️ BLE busy (0x92)\r\n");
    //     return;
    // }

    // P2P_SERVER_SendCustomMessage(msg);
    // i += 1;
    // tx_ready = 0;
    // /* 重新触发任务，相当于定时循环 */
    if (HAL_GetTick() - lastTick > 500)
    {
    lastTick = HAL_GetTick();
    P2P_SERVER_SendCustomMessage(msg);
    }

    UTIL_SEQ_SetTask(1U << CFG_TASK_SEND_CUSTOM_ID, 0);
}

void BLE_SendSampleInput(void)
{
    const uint16_t mtu_payload = 240;   // 有效负载大小（MTU=220时）
    const uint8_t *buffer = (const uint8_t *)sample_input;
    const uint16_t total = sizeof(sample_input);

    static uint16_t offset = 0;          // 当前发送偏移
    static uint32_t last_tick = 0;       // 上次发送时间戳

    /* 如果 Notify 未启用则直接返回 */
    if (P2P_SERVER_APP_Context.Switch_c_Notification_Status != Switch_c_NOTIFICATION_ON)
    {
        UTIL_SEQ_PauseTask(1U << CFG_TASK_SEND_CUSTOM_ID);
        return;
    }

    /* 控制发送速率：每 1 ms 发一次 */
    uint32_t now = HAL_GetTick();
    if (now - last_tick < 1)
    {
      UTIL_SEQ_SetTask(1U << CFG_TASK_SEND_CUSTOM_ID, 0); //下一次
      return;  // 未到 1 ms，不发
    }
        
    last_tick = now;

    /* 如果 TX buffer 忙，跳过这一轮 */
    if (!tx_ready)
        return;

    /* 全部发送完成 */
    if (offset >= total)
    {
        LOG_INFO_APP("✅ BLE send complete (%d bytes)\r\n", total);

        offset = 0;

        /* 暂停任务，等待下次 Notify 启用再恢复 */
        UTIL_SEQ_PauseTask(1U << CFG_TASK_SEND_CUSTOM_ID);
        LOG_INFO_APP("⏸️ Send task paused, waiting for next Notify enable.\r\n");
        return;
    }

    /* 当前要发送的分片 */
    uint16_t chunk = (total - offset > mtu_payload) ? mtu_payload : (total - offset);

    P2P_SERVER_Data_t data;
    data.p_Payload = (uint8_t *)&buffer[offset];
    data.Length = chunk;

    /* 发送数据包 */
    tBleStatus ret = P2P_SERVER_UpdateValue(P2P_SERVER_SWITCH_C, &data);

    if (ret == BLE_STATUS_SUCCESS)
    {
        offset += chunk;
        LOG_DEBUG_APP("📤 Sent %d/%d bytes\r\n", offset, total);
    }
    else if (ret == BLE_STATUS_INSUFFICIENT_RESOURCES)
    {
        LOG_DEBUG_APP("⚠️ BLE busy (0x92)\r\n");
        tx_ready = 0;
    }
    else
    {
        LOG_INFO_APP("❌ Notify failed: 0x%02X\r\n", ret);
        tx_ready = 1;
    }

    UTIL_SEQ_SetTask(1U << CFG_TASK_SEND_CUSTOM_ID, 0); //下一次任务
}





/* USER CODE END FD_LOCAL_FUNCTIONS */
