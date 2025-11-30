/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtLedTask.c
 *        Config:  C:/Vector/CBD1800257_D01_S32K1xx/Applications/S32K144_Start_new/S32K144_Start.dpa
 *     SW-C Type:  CtLedTask
 *  Generated at:  Mon Jun  7 11:19:43 2021
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800257
 *
 *   Description:  C-Code implementation template for SW-C <CtLedTask>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * ComM_ModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_CtLedTask.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Dio.h"
#include "Com_Cfg.h"
#include "Appl_Cbk.h"
#include "Pwm.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ComM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 *   COMM_NO_COMMUNICATION (0U)
 *   COMM_SILENT_COMMUNICATION (1U)
 *   COMM_FULL_COMMUNICATION (2U)
 *
 *********************************************************************************************************************/


#define CtLedTask_START_SEC_CODE
#include "CtLedTask_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtLedTask_InitRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_UR_CN_CAN00_06ecbb07_GetCurrentComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_UR_CN_CAN00_06ecbb07_GetMaxComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_UR_CN_CAN00_06ecbb07_GetRequestedComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_UR_CN_CAN00_06ecbb07_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CtLedTask_InitRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtLedTask_CODE) CtLedTask_InitRunnable(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtLedTask_InitRunnable
 *********************************************************************************************************************/
    static uint16 ResultBuffer[1] = {0};
    
    Adc_SetupResultBuffer(0, ResultBuffer);
    Adc_EnableGroupNotification(0);
    //使用中断触发ADC要在初始化runnable添加上述代码

Rte_Call_UR_CN_CAN00_06ecbb07_RequestComMode(COMM_FULL_COMMUNICATION);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LedRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 500ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LedRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtLedTask_CODE) LedRunnable(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LedRunnable
 *********************************************************************************************************************/

static unsigned char  LedState=0;
static int  LedCnt=0;
static unsigned char RearLeftWindowPosition = 0;
static unsigned char RearRightWindowPosition = 0;
static unsigned char RearLeftWindow = 255;
static unsigned char RearRightWindow = 99;
static unsigned char ComSendCnt = 0;

static Pwm_OutputStateType PwmState;


LedCnt++;

LedState ^= 0x01;



Dio_WriteChannel(112,LedState);//LED falshing

RearRightWindow = Dio_ReadChannel(DioConf_DioChannel_DioChannel_PTC12);//read key state
if(RearRightWindow == 1)
{
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_PTD0,0);
}
else
{
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_PTD0,1);
}
//  Rte_Write_LamCnt_u8_Signal(LedCnt);
//  Rte_Write_RearInterLight_Bool_Signal(1);

//  Rte_Write_FrontInterLight_bool_Signal(1);
//  Rte_Read_RearLeft_WindowPosition_u8_Signal(&RearLeftWindowPosition);
//  Rte_Read_RearRight_WindowPosition_u8_Signal(&RearRightWindowPosition);

// if(ComSendCnt == 10)
// {
//     Com_SendSignal(ComConf_ComSignal_RearLeft_Window, (&RearLeftWindow));
//     ComSendCnt = 0;
// }
// else
// {
//     ComSendCnt++;
// }

Adc_StartGroupConversion(0);//此处填入groupid

Pwm_SetDutyCycle(0, 16384);//50%占空比
PwmState = Pwm_GetOutputState(0);

Com_SendSignal(ComConf_ComSignal_RearRight_Window, &RearRightWindow);//规范写法第二个传参不加括号

// Com_SendSignal(ComConf_ComGroupSignal_ComGroupSignal, (&RearLeftWindow));
// Com_SendSignal(ComConf_ComGroupSignal_myComGroupSignal01, (&RearRightWindow));
// Com_SendSignalGroup(ComConf_ComSignalGroup_MySignalGroup); 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

static unsigned char Cbkcnt = 0;
//if receive signal，enter this function
FUNC(void, COM_APPL_CODE) ComCbkRx_RearLeftWindowPosition(void)
{
    Cbkcnt = 1;
}
//if timeout, enter this function
FUNC(void, COM_APPL_CODE) ComCbkToutRx_RearLeftWindowPosition(void)
{
    Com_SendSignal(ComConf_ComSignal_RearLeft_Window, (&Cbkcnt));
}

void ADC_Group0Notification(void)
{
    static uint16 Adc_Data = 0;
    static uint16 retvalue = 0;
    
    retvalue = Adc_ReadGroup(0, &Adc_Data);//一个groupid，另一个是buffer的指针
    Adc_Data = Adc_Data / 20;


    Com_SendSignal(ComConf_ComSignal_sig_LampCnt_omsg_MyECU_Lamp_oCAN00_f37e68ea_Tx, &Adc_Data);
}



#define CtLedTask_STOP_SEC_CODE
#include "CtLedTask_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
