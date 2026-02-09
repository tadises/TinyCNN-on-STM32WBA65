改过的位置

## ✅ 位置 1：`app_ble.c` → 调整广播参数（加快建链）

找到函数：

```
void APP_BLE_Procedure_Gap_Peripheral(ProcGapPeripheralId_t ProcGapPeripheralId)
```

在其中 case：

```
case PROC_GAP_PERIPH_ADVERTISE_START_FAST:
{
    paramA = ADV_INTERVAL_MIN;
    paramB = ADV_INTERVAL_MAX;
    paramC = APP_BLE_ADV_FAST;
    paramD = ADV_IND;
    break;
}
```

### 👉 修改：

```
/* USER CODE BEGIN Procedure_Gap_Peripheral_1 */
// 在文件顶部添加或在这里直接定义：
#undef  ADV_INTERVAL_MIN
#undef  ADV_INTERVAL_MAX
#define ADV_INTERVAL_MIN  (0x0020)   // 20 ms
#define ADV_INTERVAL_MAX  (0x0030)   // 30 ms
/* USER CODE END Procedure_Gap_Peripheral_1 */
```

📈 **效果**：广播间隔从默认约 100 ms 缩短到 20 ms，
 主机扫描到你设备的平均时间由 ~1 s 降到 100–200 ms。

------

## ✅ 位置 2：`app_ble.c` → 建立连接后立刻传输（降低握手延迟）

同一个函数中，找到：

```
case PROC_GAP_PERIPH_CONN_PARAM_UPDATE:
{
  paramA = CONN_INT_MS(1000);
  paramB = CONN_INT_MS(1000);
```

### 👉 修改：

```
/* USER CODE BEGIN CONN_PARAM_UPDATE */
paramA = CONN_INT_MS(7.5);  // 最快 7.5 ms
paramB = CONN_INT_MS(7.5);
paramC = 0x0000;            // 无延迟
paramD = 0x00C8;            // 2 s 超时
/* USER CODE END CONN_PARAM_UPDATE */
```

📈 **效果**：连接建立后 BLE 链路调度间隔缩短约 10×，
 Notify 传输速率更高，阶段 ③ 会更快结束。

------

## ✅ 位置 3：`app_ble.c` → 使用定向广播（Direct Advertising）

在函数：APP_BLE_Procedure_Gap_Peripheral

的switch(ProcGapPeripheralId)





注释了led相关蓝牙功能



```c
#define ADV_INTERVAL_MIN                  (0x0020)
#define ADV_INTERVAL_MAX                  (0x0030)
#define ADV_LP_INTERVAL_MIN               (0x0030)
#define ADV_LP_INTERVAL_MAX               (0x0FA0)
#define ADV_TYPE                          ADV_IND
#define ADV_FILTER                        NO_WHITE_LIST_USE
```

