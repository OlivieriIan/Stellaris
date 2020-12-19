################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
lm3s6965_startup_ccs.obj: ../lm3s6965_startup_ccs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/Programs/ti/css62/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M3 --code_state=16 -me --include_path="D:/Programs/ti/css62/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="D:/zzzProgramming/ccs-workspaces/ccsv6_2" -g --gcc --define="ccs" --define=PART_LM3S6965 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="lm3s6965_startup_ccs.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/Programs/ti/css62/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M3 --code_state=16 -me --include_path="D:/Programs/ti/css62/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="D:/zzzProgramming/ccs-workspaces/ccsv6_2" -g --gcc --define="ccs" --define=PART_LM3S6965 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


