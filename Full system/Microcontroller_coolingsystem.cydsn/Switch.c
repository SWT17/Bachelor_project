/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "switch.h"
#include "UART_1.h"

uint8 switch_state;
uint8 switch_counter;
/*Setup interrupt handler*/
CY_ISR_PROTO(switch_newState);


/* Do inital setup of interrupt and internal state*/
void Switch_Setup()
{
    switch_counter = 0;
    Switch_Startup();
    
    //Enable the interrupt on the switch.
    
    switch_input_interrupt_StartEx(switch_newState);
//    switch_input_interrupt_Start();
}

/*Controlled shutdown on switch, shutoff the input power for the switch disabling it*/
void Switch_Shutdown()
{
    Switch_output_Write(0);
}

/*Startup of the switch. Enable the input power enabling the switch*/
void Switch_Startup()
{
    //Set High input to the switch priming it.
    CyDelay(2000);
    Switch_output_Write(255);
    
}



/*Interrupt handler for the switch interrupt*/
CY_ISR(switch_newState)
{
    
    CyDelay(50);
    //Reads the state on the input pin on the PSOC recieving signal for the switch
    //If the signal is high, Read() output 1, if low it outputs 0.
    switch_state = Switch_input_Read();
    
    if(switch_counter)
    {
        UART_1_PutString("Switch has been triggered \r\n");
        /*Clears interrupts and enable detection of future interrupts*/
        Switch_input_ClearInterrupt();


        //Call system controller that new state is triggered.
        //Take switch state as parameter that the controller can use
        //To determine it's actions.
        System_newState(switch_state);
        
    }else
    {
        //Some internal stuff makes the interrupt trigger even without any wires connected.
        //This little code snippets just ignores the first interrupt after every POR (Power or Reset).
        UART_1_PutString("Switch faulty output has been triggered \r\n");
        switch_counter = 1; 
        Switch_input_ClearInterrupt();
    }
    
    

}

/* [] END OF FILE */
