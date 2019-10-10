/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Samsung Exynos SoC series Pablo driver
 *
 * Copyright (c) 2019 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef IS_HW_OIS_MCU_V1_1_1_H
#define IS_HW_OIS_MCU_V1_1_1_H

#include "is-hw-api-common.h"

enum is_hw_ois_mcu_pmu_reg_name {
	R_OIS_CPU_CONFIGURATION,
	R_OIS_CPU_STATUS,
	R_OIS_CPU_STATES,
	R_OIS_CPU_OUT,
	R_PMU_OIS_REG_CNT
};

static const struct is_reg pmu_ois_mcu_regs[] = {
	{0x3300, "OIS_CPU_CONFIGURATION"},
	{0x3304, "OIS_CPU_STATUS"},
	{0x3308, "OIS_CPU_STATES"},
	{0x330c, "OIS_CPU_OPTION"},
	{0x3320, "OIS_CPU_OUT"}
};

static const struct is_reg pmu_ois_mcu_masks[] = {
	{0x1, "LOCAL_PWR_CFG"},
	{0x1, "STATUS"},
	{0xFF, "STATES"},
	{0x1F, "OIS_CPU_OPTION"},
	{0x1, "GRESETn"}
};

enum is_hw_ois_mcu_reg_name {
	R_OIS_CM0P_BOOT,
	R_OIS_CM0P_IRQ,
	R_OIS_CM0P_SYSTICK,
	R_OIS_CM0P_CTRL0,
	R_OIS_CM0P_IRQ_STATUS,
	R_OIS_CM0P_IRQ_ENABLE,
	R_OIS_CM0P_IRQ_CLEAR,
	R_OIS_CM0P_REMAP_I2C_ADDR,
	R_OIS_CM0P_REMAP_SPI_ADDR,
	R_OIS_CM0P_REMAP_SPDMA_ADDR,
	R_OIS_CM0P_MISC0,
	R_OIS_CM0P_MISC1,
	R_OIS_REG_CNT
};

static const struct is_reg ois_mcu_regs[] = {
	{0xe000, "OIS_CM0P_BOOT"},
	{0xe004, "OIS_CM0P_IRQ"},
	{0xe008, "OIS_CM0P_SYSTICK"},
	{0xe00c, "OIS_CM0P_CTRL0"},
	{0xe010, "OIS_CM0P_IRQ_STATUS"},
	{0xe014, "OIS_CM0P_IRQ_ENABLE"},
	{0xe018, "OIS_CM0P_IRQ_CLEAR"},
	{0xe01c, "OIS_CM0P_REMAP_I2C_ADDR"},
	{0xe020, "OIS_CM0P_REMAP_SPI_ADDR"},
	{0xe024, "OIS_CM0P_REMAP_SPDMA_ADDR"},
	{0xe02c, "OIS_CM0P_MISC0"},
	{0xe030, "OIS_CM0P_MISC1"}
};

enum is_hw_ois_mcu_peri_reg_name {
	R_OIS_PERI_FS1,
	R_OIS_PERI_FS2,
	R_OIS_PERI_FS3,
	R_OIS_PERI_CON_CTRL,
	R_OIS_PUD_CTRL,
	R_OIS_PERI_USI_CON,
	R_OIS_PERI_USI_CON_CLEAR,
};

static const struct is_reg ois_mcu_peri_regs[] = {
	{0x0060, "OIS_PERI_FS1"},
	{0x0064, "OIS_PERI_FS2"},
	{0x0068, "OIS_PERI_FS3"},
	{0x0080, "OIS_PERI_CON_CTRL"},
	{0x0088, "OIS_PERI_PUD_CTRL"},
	{0x00c4, "OIS_PERI_USI_CON"},
	{0x00c8, "OIS_PERI_USI_CON_CLEAR"},
};

enum is_hw_ois_mcu_cmd_name {
	R_OIS_CMD_START,
	R_OIS_CMD_STATUS,
	R_OIS_CMD_MODE,
	R_OIS_CMD_WRITE_DATA,
	R_OIS_CMD_GYRO_RESULT,
	R_OIS_CMD_CHECKSUM,
	R_OIS_CMD_READ_STATUS,
	R_OIS_CMD_GYRO_CAL,
	R_OIS_CMD_SINE_1,
	R_OIS_CMD_SINE_2,
	R_OIS_CMD_SINE_3,
	R_OIS_CMD_CENTER_X1,
	R_OIS_CMD_CENTER_X2,
	R_OIS_CMD_CENTER_Y1,
	R_OIS_CMD_CENTER_Y2,
	R_OIS_CMD_READ_WRITE_RESULT,
	R_OIS_CMD_GYRO_SLEEP,
	R_OIS_CMD_CACTRL_WRITE,
	R_OIS_CMD_REAR_AF,
	R_OIS_CMD_REAR2_AF,
	R_OIS_CMD_START_WAVE_CHECK,
	R_OIS_CMD_AUTO_TEST_RESULT,
	R_OIS_CMD_THRESH_ERR_LEV,
	R_OIS_CMD_ERR_VAL_CNT,
	R_OIS_CMD_FREQ_LEV,
	R_OIS_CMD_AMPLI_LEV,
	R_OIS_CMD_DUM_PULSE,
	R_OIS_CMD_VYVLE_LEV,
	R_OIS_CMD_THRESH_ERR_LEV_M2,
	R_OIS_CMD_SET_COEF,
	R_OIS_CMD_OIS_SEL,
	R_OIS_CMD_REAR2_SINX_COUNT1,
	R_OIS_CMD_REAR2_SINX_COUNT2,
	R_OIS_CMD_REAR2_SINY_COUNT1,
	R_OIS_CMD_REAR2_SINY_COUNT2,
	R_OIS_CMD_REAR2_SINX_DIFF1,
	R_OIS_CMD_REAR2_SINX_DIFF2,
	R_OIS_CMD_REAR2_SINY_DIFF1,
	R_OIS_CMD_REAR2_SINY_DIFF2,
	R_OIS_CMD_REAR_SINX_COUNT1,
	R_OIS_CMD_REAR_SINX_COUNT2,
	R_OIS_CMD_REAR_SINY_COUNT1,
	R_OIS_CMD_REAR_SINY_COUNT2,
	R_OIS_CMD_REAR_SINX_DIFF1,
	R_OIS_CMD_REAR_SINX_DIFF2,
	R_OIS_CMD_REAR_SINY_DIFF1,
	R_OIS_CMD_REAR_SINY_DIFF2,
	R_OIS_CMD_GYRO_VAL_X,
	R_OIS_CMD_GYRO_LOG_X,
	R_OIS_CMD_GYRO_VAL_Y,
	R_OIS_CMD_GYRO_LOG_Y,
	R_OIS_CMD_FADE_UP1,
	R_OIS_CMD_FADE_UP2,
	R_OIS_CMD_FADE_DOWN1,
	R_OIS_CMD_FADE_DOWN2,
	R_OIS_CMD_GYRO_POLA_X,
	R_OIS_CMD_GYRO_POLA_Y,
	R_OIS_CMD_GYRO_ORIENT,
	R_OIS_CMD_RAW_DEBUG_X1,
	R_OIS_CMD_RAW_DEBUG_X2,
	R_OIS_CMD_RAW_DEBUG_Y1,
	R_OIS_CMD_RAW_DEBUG_Y2,
	R_OIS_CMD_REAR_XGG1,
	R_OIS_CMD_REAR_XGG2,
	R_OIS_CMD_REAR_XGG3,
	R_OIS_CMD_REAR_XGG4,
	R_OIS_CMD_REAR_YGG1,
	R_OIS_CMD_REAR_YGG2,
	R_OIS_CMD_REAR_YGG3,
	R_OIS_CMD_REAR_YGG4,
	R_OIS_CMD_ANGLE_COMP1,
	R_OIS_CMD_ANGLE_COMP2,
	R_OIS_CMD_ANGLE_COMP3,
	R_OIS_CMD_ANGLE_COMP4,
	R_OIS_CMD_ANGLE_COMP5,
	R_OIS_CMD_ANGLE_COMP6,
	R_OIS_CMD_ANGLE_COMP7,
	R_OIS_CMD_ANGLE_COMP8,
	R_OIS_CMD_ENABLE_DUALCAL,
	R_OIS_CMD_XCOEF_M1,
	R_OIS_CMD_YCOEF_M1,
	R_OIS_CMD_XCOEF_M2,
	R_OIS_CMD_YCOEF_M2,
	R_OIS_CMD_GYRO_POLA_X_M2,
	R_OIS_CMD_GYRO_POLA_Y_M2,
	R_OIS_CMD_REAR2_XGG1,
	R_OIS_CMD_REAR2_XGG2,
	R_OIS_CMD_REAR2_XGG3,
	R_OIS_CMD_REAR2_XGG4,
	R_OIS_CMD_REAR2_YGG1,
	R_OIS_CMD_REAR2_YGG2,
	R_OIS_CMD_REAR2_YGG3,
	R_OIS_CMD_REAR2_YGG4
};

static const struct is_reg ois_mcu_cmd_regs[] = {
	{0x7800, "OIS_CMD_START"},
	{0x7801, "OIS_CMD_STATUS"},
	{0x7802, "OIS_CMD_MODE"},
	{0x7803, "OIS_CMD_WRITE_DATA"},
	{0x7804, "OIS_CMD_GYRO_RESULT"},
	{0x7805, "OIS_CMD_CHECKSUM"},
	{0x7806, "OIS_CMD_READ_STATUS"},
	{0x7814, "OIS_CMD_GYRO_CAL"},
	{0x7818, "OIS_CMD_SINE_1"},
	{0x7819, "OIS_CMD_SINE_2"},
	{0x781A, "OIS_CMD_SINE_3"},
	{0x7822, "OIS_CMD_CENTER_X1"},
	{0x7823, "OIS_CMD_CENTER_X2"},
	{0x7824, "OIS_CMD_CENTER_Y1"},
	{0x7825, "OIS_CMD_CENTER_Y2"},
	{0x7827, "OIS_CMD_READ_WRITE_RESULT"},
	{0x7830, "OIS_CMD_GYRO_SLEEP"},
	{0x7839, "OIS_CMD_CACTRL_WRITE"},
	{0x783A, "OIS_CMD_REAR_AF"},
	{0x783B, "OIS_CMD_REAR2_AF"},
	{0x7850, "OIS_CMD_START_WAVE_CHECK"},
	{0x7851, "OIS_CMD_AUTO_TEST_RESULT"},
	{0x7852, "OIS_CMD_THRESH_ERR_LEV"},
	{0x7853, "OIS_CMD_ERR_VAL_CNT"},
	{0x7854, "OIS_CMD_FREQ_LEV"},
	{0x7855, "OIS_CMD_AMPLI_LEV"},
	{0x7856, "OIS_CMD_DUM_PULSE"},
	{0x7857, "OIS_CMD_VYVLE_LEV"},
	{0x785B, "OIS_CMD_THRESH_ERR_LEV_M2"},
	{0x785E, "OIS_CMD_SET_COEF"},
	{0x78BE, "OIS_CMD_OIS_SEL"},
	{0x78C0, "OIS_CMD_REAR2_SINX_COUNT1"},
	{0x78C1, "OIS_CMD_REAR2_SINX_COUNT2"},
	{0x78C2, "OIS_CMD_REAR2_SINY_COUNT1"},
	{0x78C3, "OIS_CMD_REAR2_SINY_COUNT2"},
	{0x78C4, "OIS_CMD_REAR2_SINX_DIFF1"},
	{0x78C5, "OIS_CMD_REAR2_SINX_DIFF2"},
	{0x78C6, "OIS_CMD_REAR2_SINY_DIFF1"},
	{0x78C7, "OIS_CMD_REAR2_SINY_DIFF2"},
	{0x78E4, "OIS_CMD_REAR_SINX_COUNT1"},
	{0x78E5, "OIS_CMD_REAR_SINX_COUNT2"},
	{0x78E6, "OIS_CMD_REAR_SINY_COUNT1"},
	{0x78E7, "OIS_CMD_REAR_SINY_COUNT2"},
	{0x78E8, "OIS_CMD_REAR_SINX_DIFF1"},
	{0x78E9, "OIS_CMD_REAR_SINX_DIFF2"},
	{0x78EA, "OIS_CMD_REAR_SINY_DIFF1"},
	{0x78EB, "OIS_CMD_REAR_SINY_DIFF2"},
	{0x78EC, "OIS_CMD_GYRO_VAL_X"},
	{0x78ED, "OIS_CMD_GYRO_LOG_X"},
	{0x78EE, "OIS_CMD_GYRO_VAL_Y"},
	{0x78EF, "OIS_CMD_GYRO_LOG_Y"},
	{0x7A38, "OIS_CMD_FADE_UP1"},
	{0x7A39, "OIS_CMD_FADE_UP2"},
	{0x7A3A, "OIS_CMD_FADE_DOWN1"},
	{0x7A3B, "OIS_CMD_FADE_DOWN2"},
	{0x7A40, "OIS_CMD_GYRO_POLA_X"},
	{0x7A41, "OIS_CMD_GYRO_POLA_Y"},
	{0x7A42, "OIS_CMD_GYRO_ORIENT"},
	{0x7A48, "OIS_CMD_RAW_DEBUG_X1"},
	{0x7A49, "OIS_CMD_RAW_DEBUG_X2"},
	{0x7A4A, "OIS_CMD_RAW_DEBUG_Y1"},
	{0x7A4B, "OIS_CMD_RAW_DEBUG_Y2"},
	{0x7A54, "OIS_CMD_REAR_XGG1"},
	{0x7A55, "OIS_CMD_REAR_XGG2"},
	{0x7A56, "OIS_CMD_REAR_XGG3"},
	{0x7A57, "OIS_CMD_REAR_XGG4"},
	{0x7A58, "OIS_CMD_REAR_YGG1"},
	{0x7A59, "OIS_CMD_REAR_YGG2"},
	{0x7A5A, "OIS_CMD_REAR_YGG3"},
	{0x7A5B, "OIS_CMD_REAR_YGG4"},
	{0x7B48, "OIS_CMD_ANGLE_COMP1"},
	{0x7B49, "OIS_CMD_ANGLE_COMP2"},
	{0x7B4A, "OIS_CMD_ANGLE_COMP3"},
	{0x7B4B, "OIS_CMD_ANGLE_COMP4"},
	{0x7BD8, "OIS_CMD_ANGLE_COMP5"},
	{0x7BD9, "OIS_CMD_ANGLE_COMP6"},
	{0x7BDA, "OIS_CMD_ANGLE_COMP7"},
	{0x7BDB, "OIS_CMD_ANGLE_COMP8"},
	{0x7C40, "OIS_CMD_ENABLE_DUALCAL"},
	{0x7C42, "OIS_CMD_XCOEF_M1"},
	{0x7C44, "OIS_CMD_YCOEF_M1"},
	{0x7C46, "OIS_CMD_XCOEF_M2"},
	{0x7C48, "OIS_CMD_YCOEF_M2"},
	{0x7D52, "OIS_CMD_GYRO_POLA_X_M2"},
	{0x7D53, "OIS_CMD_GYRO_POLA_Y_M2"},
	{0x7D54, "OIS_CMD_REAR2_XGG1"},
	{0x7D55, "OIS_CMD_REAR2_XGG2"},
	{0x7D56, "OIS_CMD_REAR2_XGG3"},
	{0x7D57, "OIS_CMD_REAR2_XGG4"},
	{0x7D58, "OIS_CMD_REAR2_YGG1"},
	{0x7D59, "OIS_CMD_REAR2_YGG2"},
	{0x7D5A, "OIS_CMD_REAR2_YGG3"},
	{0x7D5B, "OIS_CMD_REAR2_YGG4"}
};

enum is_hw_ois_mcu_cmd_field {
	OIS_F_CMD_START,		
	OIS_F_CMD_STATUS,		
	OIS_F_CMD_MODE,
	OIS_REG_CMD_FIELD_CNT
};

static const struct is_field ois_mcu_cmd_fields[OIS_REG_CMD_FIELD_CNT] = {
	/* field_name, start_bit, bit_width, type, reset */
	{"OIS_CMD_START", 0, 1, RW, 0x00000000},
	{"OIS_CMD_STATUS", 0, 1, RO, 0x00000000},
	{"OIS_CMD_MODE", 0, 1, RW, 0x00000000}
};

enum is_hw_ois_mcu_reg_field {
	OIS_F_CM0P_BOOT_REQ,		/* OIS_CM0P_BOOT */
	OIS_F_CM0P_IRQ_REQ,		/* OIS_CM0P_IRQ */
	OIS_F_CM0P_SYSTICK_NOREF,	/* OIS_CM0P_SYSTICK */
	OIS_F_CM0P_SYSTICK_SKEW,
	OIS_F_CM0P_SYSTICK_TENMS,
	OIS_F_CM0P_IPCLKREQ_ON,		/* OIS_CM0P_CTRL0 */
	OIS_F_CM0P_IPCLKREQ_ENABLE,
	OIS_F_CM0P_SLEEP_CTRL,
	OIS_F_CM0P_QACTIVE_DIRECT_CTRL,
	OIS_F_CM0P_FORCE_DBG_PWRUP,
	OIS_F_CM0P_DISABLE_IRQ,
	OIS_F_CM0P_WDTIRQ_TO_HOST,
	OIS_F_CM0P_CONNECT_WDT_TO_NMI,
	OIS_F_CM0P_SYS_RST_ASSERTED,	/* OIS_CM0P_IRQ_STATUS */
	OIS_F_CM0P_LOCKUP_RST_ASSERTED,
	OIS_F_CM0P_WDT_RST_ASSERTED,
	OIS_F_CM0P_WDT_IRQ,
	OIS_F_CM0P_SYS_RST_ENABLE,	/* OIS_CM0P_IRQ_ENABLE */
	OIS_F_CM0P_LOCKUP_RST_ENABLE,
	OIS_F_CM0P_WDT_RST_ENABLE,
	OIS_F_CM0P_WDT_IRQ_ENABLE,
	OIS_F_CM0P_SYS_RST__CLEAR,	/* OIS_CM0P_IRQ_CLEAR */
	OIS_F_CM0P_LOCKUP_RST_CLEAR,
	OIS_F_CM0P_WDT_RST_CLEAR,
	OIS_F_CM0P_WDT_IRQ_CLEAR,
	OIS_F_CM0P_I2C_ADDR,
	OIS_F_CM0P_SPI_ADDR,
	OIS_F_CM0P_SPDMA_ADDR,
	OIS_F_CM0P_MISC0,
	OIS_F_CM0P_MISC1,
	OIS_REG_FIELD_CNT
};

static const struct is_field ois_mcu_fields[OIS_REG_FIELD_CNT] = {
	/* field_name, start_bit, bit_width, type, reset */
	{"OIS_CM0P_BOOT_REQ", 0, 1, RW, 0x00000000},
	{"OIS_CM0P_IRQ_REQ", 0, 1, RW, 0x00000000},
	{"OIS_CM0P_SYSTICK_NOREF", 25, 1, RW, 0x00000000},
	{"OIS_CM0P_SYSTICK_SKEW", 24, 1, RW, 0x00000000},
	{"OIS_CM0P_SYSTICK_TENMS", 0, 24, RW, 0x0000F42F}, /* default: 100MHz */
	{"OIS_CM0P_IPCLKREQ_ON", 28, 1, RW, 0x00000000},
	{"OIS_CM0P_IPCLKREQ_ENABLE", 27, 1, RW, 0x00000000},
	{"OIS_CM0P_SLEEP_CTRL", 26, 1, RW, 0x00000000},
	{"OIS_CM0P_QACTIVE_DIRECT_CTRL", 25, 1, RW, 0x00000001},
	{"OIS_CM0P_FORCE_DBG_PWRUP", 24, 1, RW, 0x00000001},
	{"OIS_CM0P_DISABLE_IRQ", 16, 1, RW, 0x00000000},
	{"OIS_CM0P_WDTIRQ_TO_HOST", 1, 1, RW, 0x00000000},
	{"OIS_CM0P_CONNECT_WDT_TO_NMI", 0, 1, RW, 0x00000000},
	{"OIS_CM0P_SYS_RST_ASSERTED", 3, 1, RO, 0x00000000},
	{"OIS_CM0P_LOCKUP_RST_ASSERTED", 2, 1, RO, 0x00000000},
	{"OIS_CM0P_WDT_RST_ASSERTED", 1, 1, RO, 0x00000000},
	{"OIS_CM0P_WDT_IRQ", 0, 1, RO, 0x00000000},
	{"OIS_CM0P_SYS_RST_ENABLE", 3, 1, RW, 0x00000000},
	{"OIS_CM0P_LOCKUP_RST_ENABLE", 2, 1, RW, 0x00000000},
	{"OIS_CM0P_WDT_RST_ENABLE", 1, 1, RW, 0x00000000},
	{"OIS_CM0P_WDT_IRQ_ENABLE", 0, 1, RW, 0x00000000},
	{"OIS_CM0P_SYS_RST_CLEAR", 3, 1, RW, 0x00000000},
	{"OIS_CM0P_LOCKUP_RST_CLEAR", 2, 1, RW, 0x00000000},
	{"OIS_CM0P_WDT_RST_CLEAR", 1, 1, RW, 0x00000000},
	{"OIS_CM0P_WDT_IRQ_CLEAR", 0, 1, RW, 0x00000000},
	{"OIS_CM0P_I2C_ADDR", 0, 32, RW, 0x00000000},
	{"OIS_CM0P_SPI_ADDR", 0, 32, RW, 0x00000000},
	{"OIS_CM0P_REMAP_SPDMA_ADDR", 0, 32, RW, 0x00000000},
	{"OIS_CM0P_MISC0", 0, 32, RW, 0x00000000},
	{"OIS_CM0P_MISC1", 0, 32, RW, 0x00000000}
};

#endif
