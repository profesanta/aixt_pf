// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: PWM.v
// Author: Fernando Martínez Santa - Stiven Cortazar Cortazar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: PWM Ouput functions (Ai-Thinker_Ai-WB2-32S-Kit)
//              (PC port) 

import time {sleep_ms}
import pin
import pwm

__global val = 0

pin.setup(17, pin.out)

for {
    pwm.write(17, val)
    sleep_ms(250)
    val=val+10
    if val==250{
		val=0  
    }
} 