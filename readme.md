![image](https://github.com/tadises/TinyCNN-on-STM32WBA65/images/2current)

![image](https://github.com/tadises/TinyCNN-on-STM32WBA65/images/4comparison)


The proposed model was successfully deployed on the STM32WBA65 microcontroller using the STM32 X-CUBE-AI toolchain for on-device inference. Power consumption measurements were conducted under multiple operating configurations to evaluate the energy efficiency of the system during a one-minute duty cycle consisting of startup, inference, and low-power standby or stop modes.

Experimental results demonstrate that the system achieves ultra-low energy consumption during inference, with MCU active energy remaining below 0.03 μAh in all tested configurations. In standby mode, the device exhibits extremely low quiescent current (approximately 4.5 μA), resulting in a total energy consumption of less than 0.1 μAh per minute. When operating in stop mode, although the MCU runtime energy is further reduced, the higher stop-mode current leads to a significantly increased standby energy, yielding a total consumption of approximately 1.1 μAh per minute.

For comparison, a baseline scenario involving direct startup and raw data transmission via Bluetooth shows substantially higher energy usage, exceeding 5.7 μAh per minute, highlighting the advantage of on-device inference in reducing both communication and power overhead.

The quantitative results are summarized in two bar charts: one comparing standby current across low-power modes (stop versus standby), and another presenting a combined comparison of total energy consumption under different operating configurations. These results confirm that the proposed embedded deployment strategy achieves both high inference efficiency and excellent power performance, making it suitable for long-term, battery-powered operation.


It should be noted that the Bluetooth communication stack used in this study was not yet optimized. Even under this unoptimized configuration, the energy consumption of transmitting a single Bluetooth data packet reaches approximately 0.003878 μAh. Consequently, the energy required to transmit only five data packets is already comparable to the energy consumed by a full startup and inference cycle at 100 MHz. Moreover, the energy overhead associated with Bluetooth connection establishment and sustained data transmission far exceeds that of transmitting a small number of packets. These findings further emphasize the significant energy savings achieved by performing inference directly on-device rather than relying on continuous wireless data transmission.


