#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC18F4620Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC18F4620Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_layer/BUTTON/ecu_button.c ECU_layer/DCmotor/ecu_dcmotor.c ECU_layer/KEYPAD/ecu_keypad.c ECU_layer/LCD/ecu_lcd.c ECU_layer/LED/ecu_led.c ECU_layer/RELAY/ecu_relay.c ECU_layer/SSD/ecu_ssd.c ECU_layer/ecu_layer_init.c MCAL_layer/GPIO/hal_gpio.c MCAL_layer/device_config.c application.c MCAL_layer/interrupt/mcal_external_interrupt.c MCAL_layer/interrupt/mcal_internal_interrupt.c MCAL_layer/interrupt/mcal_interrupt_manager.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1 ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1 ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1 ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_layer/device_config.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1.d ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1.d ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1.d ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d ${OBJECTDIR}/application.p1.d ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1 ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1 ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1 ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_layer/device_config.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1

# Source Files
SOURCEFILES=ECU_layer/BUTTON/ecu_button.c ECU_layer/DCmotor/ecu_dcmotor.c ECU_layer/KEYPAD/ecu_keypad.c ECU_layer/LCD/ecu_lcd.c ECU_layer/LED/ecu_led.c ECU_layer/RELAY/ecu_relay.c ECU_layer/SSD/ecu_ssd.c ECU_layer/ecu_layer_init.c MCAL_layer/GPIO/hal_gpio.c MCAL_layer/device_config.c application.c MCAL_layer/interrupt/mcal_external_interrupt.c MCAL_layer/interrupt/mcal_internal_interrupt.c MCAL_layer/interrupt/mcal_interrupt_manager.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PIC18F4620Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1: ECU_layer/BUTTON/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1 ECU_layer/BUTTON/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.d ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1: ECU_layer/DCmotor/ecu_dcmotor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/DCmotor" 
	@${RM} ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1 ECU_layer/DCmotor/ecu_dcmotor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.d ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1: ECU_layer/KEYPAD/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 ECU_layer/KEYPAD/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.d ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1: ECU_layer/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ECU_layer/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.d ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LED/ecu_led.p1: ECU_layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ECU_layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LED/ecu_led.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1: ECU_layer/RELAY/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/RELAY" 
	@${RM} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 ECU_layer/RELAY/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.d ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1: ECU_layer/SSD/ecu_ssd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/SSD" 
	@${RM} ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1 ECU_layer/SSD/ecu_ssd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.d ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/ecu_layer_init.p1: ECU_layer/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer" 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 ECU_layer/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/ecu_layer_init.d ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1: MCAL_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 MCAL_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/device_config.p1: MCAL_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/device_config.p1 MCAL_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/device_config.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1: MCAL_layer/interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1 MCAL_layer/interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1: MCAL_layer/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1 MCAL_layer/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1: MCAL_layer/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1 MCAL_layer/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1: ECU_layer/BUTTON/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1 ECU_layer/BUTTON/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.d ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/BUTTON/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1: ECU_layer/DCmotor/ecu_dcmotor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/DCmotor" 
	@${RM} ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1 ECU_layer/DCmotor/ecu_dcmotor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.d ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/DCmotor/ecu_dcmotor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1: ECU_layer/KEYPAD/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 ECU_layer/KEYPAD/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.d ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1: ECU_layer/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ECU_layer/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.d ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LED/ecu_led.p1: ECU_layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ECU_layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LED/ecu_led.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1: ECU_layer/RELAY/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/RELAY" 
	@${RM} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 ECU_layer/RELAY/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.d ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1: ECU_layer/SSD/ecu_ssd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/SSD" 
	@${RM} ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1 ECU_layer/SSD/ecu_ssd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.d ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/SSD/ecu_ssd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/ecu_layer_init.p1: ECU_layer/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer" 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 ECU_layer/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/ecu_layer_init.d ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1: MCAL_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 MCAL_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/device_config.p1: MCAL_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/device_config.p1 MCAL_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/device_config.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1: MCAL_layer/interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1 MCAL_layer/interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1: MCAL_layer/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1 MCAL_layer/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1: MCAL_layer/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1 MCAL_layer/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PIC18F4620Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC18F4620Drivers.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC18F4620Drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/PIC18F4620Drivers.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/PIC18F4620Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC18F4620Drivers.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC18F4620Drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
