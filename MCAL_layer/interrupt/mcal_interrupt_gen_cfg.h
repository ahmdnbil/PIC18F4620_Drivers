/**
 * @file mcal_interrupt_gen_cfg.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define MCAL_INTERRUPT_GEN_CFG_H

/*-------------------------------------section includes---------------------------------------*/
/*---------------------------------------MACRO Declarations-----------------------------------*/

#define  INTERRUPT_FEATURE_ENABLE 1U
#define  INTERRUPT_FEATURE_DISABLE 0U

#define INTERRUPT_PRIORITY_LEVELS_ENABLE INTERRUPT_FEATURE_DISABLE
#define EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/

#endif /* MCAL_INTERRUPT_GEN_CFG_H */
