/*
 * linux/drivers/video/fbdev/exynos/panel/s6e3ha9/s6e3ha9_davinci_panel_poc.h
 *
 * Header file for POC Driver
 *
 * Copyright (c) 2016 Samsung Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __S6E3HA9_DAVINCI_PANEL_POC_H__
#define __S6E3HA9_DAVINCI_PANEL_POC_H__

#include "../panel.h"
#include "../panel_poc.h"

#define DAVINCI_BDIV	(BIT_RATE_DIV_32)
#define DAVINCI_EXEC_USEC	(2)
#define DAVINCI_QD_DONE_MDELAY		(30)
#define DAVINCI_RD_DONE_UDELAY		(70)
#define DAVINCI_WR_ENABLE_01_UDELAY		(20)
#define DAVINCI_WR_ENABLE_02_MDELAY		(10)
#define DAVINCI_WR_EXEC_UDELAY		(400)
#define DAVINCI_WR_DONE_MDELAY		(1)
#ifdef CONFIG_SUPPORT_POC_FLASH
#define DAVINCI_ER_4K_DONE_MDELAY		(400)
#define DAVINCI_ER_32K_DONE_MDELAY		(800)
#define DAVINCI_ER_64K_DONE_MDELAY		(1000)
#endif

#define DAVINCI_POC_IMG_ADDR	(0)
#define DAVINCI_POC_IMG_SIZE	(551186)

#ifdef CONFIG_SUPPORT_DIM_FLASH
#define DAVINCI_POC_DIM_DATA_ADDR	(0xA0000)
#define DAVINCI_POC_DIM_DATA_SIZE (S6E3HA9_DIM_FLASH_DATA_SIZE)
#define DAVINCI_POC_DIM_CHECKSUM_ADDR	(DAVINCI_POC_DIM_DATA_ADDR + S6E3HA9_DIM_FLASH_CHECKSUM_OFS)
#define DAVINCI_POC_DIM_CHECKSUM_SIZE (S6E3HA9_DIM_FLASH_CHECKSUM_LEN)
#define DAVINCI_POC_DIM_MAGICNUM_ADDR	(DAVINCI_POC_DIM_DATA_ADDR + S6E3HA9_DIM_FLASH_MAGICNUM_OFS)
#define DAVINCI_POC_DIM_MAGICNUM_SIZE (S6E3HA9_DIM_FLASH_MAGICNUM_LEN)
#define DAVINCI_POC_DIM_TOTAL_SIZE (S6E3HA9_DIM_FLASH_TOTAL_SIZE)

#define DAVINCI_POC_MTP_DATA_ADDR	(0xA2000)
#define DAVINCI_POC_MTP_DATA_SIZE (S6E3HA9_DIM_FLASH_MTP_DATA_SIZE)
#define DAVINCI_POC_MTP_CHECKSUM_ADDR	(DAVINCI_POC_MTP_DATA_ADDR + S6E3HA9_DIM_FLASH_MTP_CHECKSUM_OFS)
#define DAVINCI_POC_MTP_CHECKSUM_SIZE (S6E3HA9_DIM_FLASH_MTP_CHECKSUM_LEN)
#define DAVINCI_POC_MTP_TOTAL_SIZE (S6E3HA9_DIM_FLASH_MTP_TOTAL_SIZE)
#endif

#define DAVINCI_POC_MCD_ADDR	(0xB8000)
#define DAVINCI_POC_MCD_SIZE (S6E3HA9_FLASH_MCD_LEN)

#ifdef CONFIG_SUPPORT_POC_SPI
#define DAVINCI_SPI_WR_DONE_UDELAY		(400)
#endif

/* ===================================================================================== */
/* ============================== [S6E3HA9 MAPPING TABLE] ============================== */
/* ===================================================================================== */
static struct maptbl davinci_poc_maptbl[] = {
	[POC_WR_ADDR_MAPTBL] = DEFINE_0D_MAPTBL(davinci_poc_wr_addr_table, init_common_table, NULL, copy_poc_wr_addr_maptbl),
	[POC_RD_ADDR_MAPTBL] = DEFINE_0D_MAPTBL(davinci_poc_rd_addr_table, init_common_table, NULL, copy_poc_rd_addr_maptbl),
	[POC_WR_DATA_MAPTBL] = DEFINE_0D_MAPTBL(davinci_poc_wr_data_table, init_common_table, NULL, copy_poc_wr_data_maptbl),
#ifdef CONFIG_SUPPORT_POC_FLASH
	[POC_ER_ADDR_MAPTBL] = DEFINE_0D_MAPTBL(davinci_poc_er_addr_table, init_common_table, NULL, copy_poc_er_addr_maptbl),
#endif
#ifdef CONFIG_SUPPORT_POC_SPI
	[POC_SPI_READ_ADDR_MAPTBL] = DEFINE_0D_MAPTBL(davinci_poc_spi_read_table, init_common_table, NULL, copy_poc_rd_addr_maptbl),
	[POC_SPI_WRITE_ADDR_MAPTBL] = DEFINE_0D_MAPTBL(davinci_poc_spi_write_addr_table, init_common_table, NULL, copy_poc_wr_addr_maptbl),
	[POC_SPI_WRITE_DATA_MAPTBL] = DEFINE_0D_MAPTBL(davinci_poc_spi_write_data_table, init_common_table, NULL, copy_poc_wr_data_maptbl),
	[POC_SPI_ERASE_ADDR_MAPTBL] = DEFINE_0D_MAPTBL(davinci_poc_spi_erase_addr_table, init_common_table, NULL, copy_poc_er_addr_maptbl),
#endif
};

/* ===================================================================================== */
/* ============================== [S6E3HA9 COMMAND TABLE] ============================== */
/* ===================================================================================== */
static u8 DAVINCI_KEY2_ENABLE[] = { 0xF0, 0x5A, 0x5A };
static u8 DAVINCI_KEY2_DISABLE[] = { 0xF0, 0xA5, 0xA5 };
static u8 DAVINCI_POC_KEY_ENABLE[] = { 0xF1, 0xF1, 0xA2 };
static u8 DAVINCI_POC_KEY_DISABLE[] = { 0xF1, 0xA5, 0xA5 };
static u8 DAVINCI_POC_PGM_ENABLE[] = { 0xC0, 0x02 };
static u8 DAVINCI_POC_PGM_DISABLE[] = { 0xC0, 0x00 };
static u8 DAVINCI_POC_EXEC[] = { 0xC0, 0x03 };
#ifdef CONFIG_SUPPORT_POC_FLASH
static u8 DAVINCI_POC_ER_CTRL_01[] = { 0xC1, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04 };
static u8 DAVINCI_POC_ER_CTRL_02[] = { 0xC1, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x10, 0x04 };
static u8 DAVINCI_POC_ER_4K_STT[] = { 0xC1, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x04 };
static u8 DAVINCI_POC_ER_32K_STT[] = { 0xC1, 0x00, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x04 };
static u8 DAVINCI_POC_ER_64K_STT[] = { 0xC1, 0x00, 0x00, 0x00, 0xD8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x04 };
#endif
static u8 DAVINCI_POC_RD_ENABLE[] = { 0xC1, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, DAVINCI_BDIV };
static u8 DAVINCI_POC_QD_ENABLE[] = { 0xC1, 0x00, 0x00, 0x00, 0x01, 0x5E, 0x02, 0x00, 0x00, 0x00, 0x00, 0x10, 0x04 };
static u8 DAVINCI_POC_RD_STT[] = { 0xC1, 0x00, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, DAVINCI_BDIV, 0x01 };

static u8 DAVINCI_POC_WR_ENABLE_01[] = { 0xC1, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04 };
static u8 DAVINCI_POC_WR_ENABLE_02[] = { 0xC1, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x10, 0x04 };
static u8 DAVINCI_POC_WR_END[] = { 0xC1, 0x00, 0x00, 0xFF, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x04, 0x01 };
static u8 DAVINCI_POC_WR_EXIT[] = { 0xC1, 0x00, 0x00, 0x00, 0x01, 0x5E, 0x02, 0x00, 0x00, 0x00, 0x00, 0x10, 0x04 };
static u8 DAVINCI_POC_WR_STT_DAT[] = { 0xC1, 0x00, 0x00, 0xFF, 0x32, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, //addr
	0x40, 0x04, 0x01,
	//data
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};


static DEFINE_STATIC_PACKET(davinci_level2_key_enable, DSI_PKT_TYPE_WR, DAVINCI_KEY2_ENABLE, 0);
static DEFINE_STATIC_PACKET(davinci_level2_key_disable, DSI_PKT_TYPE_WR, DAVINCI_KEY2_DISABLE, 0);
static DEFINE_STATIC_PACKET(davinci_poc_key_enable, DSI_PKT_TYPE_WR, DAVINCI_POC_KEY_ENABLE, 0);
static DEFINE_STATIC_PACKET(davinci_poc_key_disable, DSI_PKT_TYPE_WR, DAVINCI_POC_KEY_DISABLE, 0);
static DEFINE_STATIC_PACKET(davinci_poc_pgm_enable, DSI_PKT_TYPE_WR, DAVINCI_POC_PGM_ENABLE, 0);
static DEFINE_STATIC_PACKET(davinci_poc_pgm_disable, DSI_PKT_TYPE_WR, DAVINCI_POC_PGM_DISABLE, 0);
#ifdef CONFIG_SUPPORT_POC_FLASH
static DEFINE_STATIC_PACKET(davinci_poc_er_ctrl_01, DSI_PKT_TYPE_WR, DAVINCI_POC_ER_CTRL_01, 0);
static DEFINE_STATIC_PACKET(davinci_poc_er_ctrl_02, DSI_PKT_TYPE_WR, DAVINCI_POC_ER_CTRL_02, 0);
static DEFINE_PKTUI(davinci_poc_er_4k_stt, &davinci_poc_maptbl[POC_ER_ADDR_MAPTBL], 5);
static DEFINE_VARIABLE_PACKET(davinci_poc_er_4k_stt, DSI_PKT_TYPE_WR, DAVINCI_POC_ER_4K_STT, 0);
static DEFINE_PANEL_MDELAY(davinci_poc_wait_er_4k_done, DAVINCI_ER_4K_DONE_MDELAY);
static DEFINE_PKTUI(davinci_poc_er_32k_stt, &davinci_poc_maptbl[POC_ER_ADDR_MAPTBL], 5);
static DEFINE_VARIABLE_PACKET(davinci_poc_er_32k_stt, DSI_PKT_TYPE_WR, DAVINCI_POC_ER_32K_STT, 0);
static DEFINE_PANEL_MDELAY(davinci_poc_wait_er_32k_done, DAVINCI_ER_32K_DONE_MDELAY);
static DEFINE_PKTUI(davinci_poc_er_64k_stt, &davinci_poc_maptbl[POC_ER_ADDR_MAPTBL], 5);
static DEFINE_VARIABLE_PACKET(davinci_poc_er_64k_stt, DSI_PKT_TYPE_WR, DAVINCI_POC_ER_64K_STT, 0);
static DEFINE_PANEL_MDELAY(davinci_poc_wait_er_64k_done, DAVINCI_ER_64K_DONE_MDELAY);
#endif
static DEFINE_STATIC_PACKET(davinci_poc_exec, DSI_PKT_TYPE_WR, DAVINCI_POC_EXEC, 0);
static DEFINE_STATIC_PACKET(davinci_poc_rd_enable, DSI_PKT_TYPE_WR, DAVINCI_POC_RD_ENABLE, 0);
static DEFINE_STATIC_PACKET(davinci_poc_qd_enable, DSI_PKT_TYPE_WR, DAVINCI_POC_QD_ENABLE, 0);
static DEFINE_STATIC_PACKET(davinci_poc_wr_enable_01, DSI_PKT_TYPE_WR, DAVINCI_POC_WR_ENABLE_01, 0);
static DEFINE_STATIC_PACKET(davinci_poc_wr_enable_02, DSI_PKT_TYPE_WR, DAVINCI_POC_WR_ENABLE_02, 0);
static DEFINE_STATIC_PACKET(davinci_poc_wr_end, DSI_PKT_TYPE_WR, DAVINCI_POC_WR_END, 0);
static DEFINE_STATIC_PACKET(davinci_poc_wr_exit, DSI_PKT_TYPE_WR, DAVINCI_POC_WR_EXIT, 0);
static DEFINE_PKTUI(davinci_poc_rd_stt, &davinci_poc_maptbl[POC_RD_ADDR_MAPTBL], 8);
static DEFINE_VARIABLE_PACKET(davinci_poc_rd_stt, DSI_PKT_TYPE_WR, DAVINCI_POC_RD_STT, 0);
static DECLARE_PKTUI(davinci_poc_wr_stt_dat) = {
	{ .offset = 8, .maptbl = &davinci_poc_maptbl[POC_WR_ADDR_MAPTBL] },
	{ .offset = 14, .maptbl = &davinci_poc_maptbl[POC_WR_DATA_MAPTBL] },
};
static DEFINE_VARIABLE_PACKET(davinci_poc_wr_stt_dat, DSI_PKT_TYPE_WR, DAVINCI_POC_WR_STT_DAT, 0);

static DEFINE_PANEL_UDELAY_NO_SLEEP(davinci_poc_wait_exec, DAVINCI_EXEC_USEC);
static DEFINE_PANEL_UDELAY_NO_SLEEP(davinci_poc_wait_rd_done, DAVINCI_RD_DONE_UDELAY);
static DEFINE_PANEL_UDELAY_NO_SLEEP(davinci_poc_wait_wr_exec, DAVINCI_WR_EXEC_UDELAY);
static DEFINE_PANEL_MDELAY(davinci_poc_wait_wr_done, DAVINCI_WR_DONE_MDELAY);
static DEFINE_PANEL_UDELAY_NO_SLEEP(davinci_poc_wait_wr_enable_01, DAVINCI_WR_ENABLE_01_UDELAY);
static DEFINE_PANEL_MDELAY(davinci_poc_wait_wr_enable_02, DAVINCI_WR_ENABLE_02_MDELAY);
static DEFINE_PANEL_MDELAY(davinci_poc_wait_qd_status, DAVINCI_QD_DONE_MDELAY);

#ifdef CONFIG_SUPPORT_POC_SPI
static u8 DAVINCI_POC_SPI_EXIT_QPI[] = { 0xFF };
static u8 DAVINCI_POC_SPI_SET_STATUS1[] = { 0x01, 0x00 };
static u8 DAVINCI_POC_SPI_SET_STATUS2[] = { 0x31, 0x00 };
static DEFINE_STATIC_PACKET(davinci_poc_spi_exit_qpi, SPI_PKT_TYPE_WR, DAVINCI_POC_SPI_EXIT_QPI, 0);
static DEFINE_STATIC_PACKET(davinci_poc_spi_set_status1, SPI_PKT_TYPE_WR, DAVINCI_POC_SPI_SET_STATUS1, 0);
static DEFINE_STATIC_PACKET(davinci_poc_spi_set_status2, SPI_PKT_TYPE_WR, DAVINCI_POC_SPI_SET_STATUS2, 0);
static u8 DAVINCI_POC_SPI_STATUS1[] = { 0x05 };
static u8 DAVINCI_POC_SPI_STATUS2[] = { 0x35 };
static u8 DAVINCI_POC_SPI_READ[] = { 0x03, 0x00, 0x00, 0x00 };
static u8 DAVINCI_POC_SPI_ERASE_4K[] = { 0x20, 0x00, 0x00, 0x00 };
static u8 DAVINCI_POC_SPI_ERASE_32K[] = { 0x52, 0x00, 0x00, 0x00 };
static u8 DAVINCI_POC_SPI_ERASE_64K[] = { 0xD8, 0x00, 0x00, 0x00 };
static u8 DAVINCI_POC_SPI_WRITE_ENABLE[] = { 0x06 };
static u8 DAVINCI_POC_SPI_WRITE[260] = { 0x02, 0x00, 0x00, 0x00, };
static DEFINE_STATIC_PACKET(davinci_poc_spi_status1, SPI_PKT_TYPE_SETPARAM, DAVINCI_POC_SPI_STATUS1, 0);
static DEFINE_STATIC_PACKET(davinci_poc_spi_status2, SPI_PKT_TYPE_SETPARAM, DAVINCI_POC_SPI_STATUS2, 0);
static DEFINE_STATIC_PACKET(davinci_poc_spi_write_enable, SPI_PKT_TYPE_WR, DAVINCI_POC_SPI_WRITE_ENABLE, 0);
static DEFINE_PKTUI(davinci_poc_spi_erase_4k, &davinci_poc_maptbl[POC_SPI_ERASE_ADDR_MAPTBL], 1);
static DEFINE_VARIABLE_PACKET(davinci_poc_spi_erase_4k, SPI_PKT_TYPE_WR, DAVINCI_POC_SPI_ERASE_4K, 0);
static DEFINE_PKTUI(davinci_poc_spi_erase_32k, &davinci_poc_maptbl[POC_SPI_ERASE_ADDR_MAPTBL], 1);
static DEFINE_VARIABLE_PACKET(davinci_poc_spi_erase_32k, SPI_PKT_TYPE_WR, DAVINCI_POC_SPI_ERASE_32K, 0);
static DEFINE_PKTUI(davinci_poc_spi_erase_64k, &davinci_poc_maptbl[POC_SPI_ERASE_ADDR_MAPTBL], 1);
static DEFINE_VARIABLE_PACKET(davinci_poc_spi_erase_64k, SPI_PKT_TYPE_WR, DAVINCI_POC_SPI_ERASE_64K, 0);

static DECLARE_PKTUI(davinci_poc_spi_write) = {
	{ .offset = 1, .maptbl = &davinci_poc_maptbl[POC_SPI_WRITE_ADDR_MAPTBL] },
	{ .offset = 4, .maptbl = &davinci_poc_maptbl[POC_SPI_WRITE_DATA_MAPTBL] },
};
static DEFINE_VARIABLE_PACKET(davinci_poc_spi_write, SPI_PKT_TYPE_WR, DAVINCI_POC_SPI_WRITE, 0);
static DEFINE_PANEL_UDELAY(davinci_poc_spi_write_done, DAVINCI_SPI_WR_DONE_UDELAY);

static DEFINE_PKTUI(davinci_poc_spi_rd_addr, &davinci_poc_maptbl[POC_SPI_READ_ADDR_MAPTBL], 1);
static DEFINE_VARIABLE_PACKET(davinci_poc_spi_rd_addr, SPI_PKT_TYPE_SETPARAM, DAVINCI_POC_SPI_READ, 0);
#endif


#ifdef CONFIG_SUPPORT_POC_FLASH
static void *davinci_poc_erase_enter_cmdtbl[] = {
	&PKTINFO(davinci_level2_key_enable),
	&PKTINFO(davinci_poc_key_enable),
	&PKTINFO(davinci_poc_pgm_enable),
	&PKTINFO(davinci_poc_er_ctrl_01),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_wr_enable_01),
	&PKTINFO(davinci_poc_er_ctrl_02),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_wr_enable_02),
};

static void *davinci_poc_erase_4k_cmdtbl[] = {
	&PKTINFO(davinci_poc_er_ctrl_01),
	&PKTINFO(davinci_poc_exec),
	&PKTINFO(davinci_poc_er_4k_stt),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_er_4k_done),
};

static void *davinci_poc_erase_32k_cmdtbl[] = {
	&PKTINFO(davinci_poc_er_ctrl_01),
	&PKTINFO(davinci_poc_exec),
	&PKTINFO(davinci_poc_er_32k_stt),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_er_32k_done),
};

static void *davinci_poc_erase_64k_cmdtbl[] = {
	&PKTINFO(davinci_poc_er_ctrl_01),
	&PKTINFO(davinci_poc_exec),
	&PKTINFO(davinci_poc_er_64k_stt),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_er_64k_done),
};

static void *davinci_poc_erase_exit_cmdtbl[] = {
	&PKTINFO(davinci_poc_pgm_disable),
	&PKTINFO(davinci_poc_key_disable),
	&PKTINFO(davinci_level2_key_disable),
};
#endif

static void *davinci_poc_wr_enter_cmdtbl[] = {
	&PKTINFO(davinci_level2_key_enable),
	&PKTINFO(davinci_poc_key_enable),
	&PKTINFO(davinci_poc_pgm_enable),
	&PKTINFO(davinci_poc_wr_enable_01),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_wr_enable_01),
	&PKTINFO(davinci_poc_wr_enable_02),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_wr_enable_02),
};

static void *davinci_poc_wr_dat_cmdtbl[] = {
	&PKTINFO(davinci_poc_wr_enable_01),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_wr_enable_01),
	&PKTINFO(davinci_poc_wr_stt_dat),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_wr_exec),
	&PKTINFO(davinci_poc_wr_end),
	&DLYINFO(davinci_poc_wait_wr_done),
};
static void *davinci_poc_wr_exit_cmdtbl[] = {
	&PKTINFO(davinci_poc_pgm_disable),
	&PKTINFO(davinci_poc_key_disable),
	&PKTINFO(davinci_level2_key_disable),
};

static void *davinci_poc_rd_enter_cmdtbl[] = {
	&PKTINFO(davinci_level2_key_enable),
	&PKTINFO(davinci_poc_key_enable),
	&PKTINFO(davinci_poc_pgm_enable),
	&PKTINFO(davinci_poc_rd_enable),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_exec),
	&PKTINFO(davinci_poc_qd_enable),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_qd_status),
};

static void *davinci_poc_rd_dat_cmdtbl[] = {
	&PKTINFO(davinci_poc_rd_stt),
	&PKTINFO(davinci_poc_exec),
	&DLYINFO(davinci_poc_wait_rd_done),
	&s6e3ha9_restbl[RES_POC_DATA],
};

static void *davinci_poc_rd_exit_cmdtbl[] = {
	&PKTINFO(davinci_poc_pgm_disable),
	&PKTINFO(davinci_poc_pgm_enable),
	&PKTINFO(davinci_poc_wr_enable_01),
	&PKTINFO(davinci_poc_exec),
	&PKTINFO(davinci_poc_wr_exit),
	&PKTINFO(davinci_poc_exec),
	&PKTINFO(davinci_poc_pgm_disable),
	&PKTINFO(davinci_poc_key_disable),
	&PKTINFO(davinci_level2_key_disable),
};
#ifdef CONFIG_SUPPORT_POC_SPI
static void *davinci_poc_spi_init_cmdtbl[] = {
	&PKTINFO(davinci_poc_spi_exit_qpi),
	&PKTINFO(davinci_poc_spi_write_enable),
	&PKTINFO(davinci_poc_spi_set_status1),
	&PKTINFO(davinci_poc_spi_write_enable),
	&PKTINFO(davinci_poc_spi_set_status2),
};

static void *davinci_poc_spi_read_cmdtbl[] = {
	&PKTINFO(davinci_poc_spi_rd_addr),
	&s6e3ha9_restbl[RES_POC_SPI_READ],
};

static void *davinci_poc_spi_erase_4k_cmdtbl[] = {
	&PKTINFO(davinci_poc_spi_write_enable),
	&PKTINFO(davinci_poc_spi_erase_4k),
};

static void *davinci_poc_spi_erase_32k_cmdtbl[] = {
	&PKTINFO(davinci_poc_spi_write_enable),
	&PKTINFO(davinci_poc_spi_erase_32k),
};

static void *davinci_poc_spi_erase_64k_cmdtbl[] = {
	&PKTINFO(davinci_poc_spi_write_enable),
	&PKTINFO(davinci_poc_spi_erase_64k),
};

static void *davinci_poc_spi_write_cmdtbl[] = {
	&PKTINFO(davinci_poc_spi_write_enable),
	&PKTINFO(davinci_poc_spi_write),
	&DLYINFO(davinci_poc_spi_write_done),
};

static void *davinci_poc_spi_status_cmdtbl[] = {
	&PKTINFO(davinci_poc_spi_status1),
	&s6e3ha9_restbl[RES_POC_SPI_STATUS1],
	&PKTINFO(davinci_poc_spi_status2),
	&s6e3ha9_restbl[RES_POC_SPI_STATUS2],
};
#endif

static struct seqinfo davinci_poc_seqtbl[MAX_POC_SEQ] = {
#ifdef CONFIG_SUPPORT_POC_FLASH
	/* poc erase */
	[POC_ERASE_ENTER_SEQ] = SEQINFO_INIT("poc-erase-enter-seq", davinci_poc_erase_enter_cmdtbl),
	[POC_ERASE_4K_SEQ] = SEQINFO_INIT("poc-erase-4k-seq", davinci_poc_erase_4k_cmdtbl),
	[POC_ERASE_32K_SEQ] = SEQINFO_INIT("poc-erase-32k-seq", davinci_poc_erase_32k_cmdtbl),
	[POC_ERASE_64K_SEQ] = SEQINFO_INIT("poc-erase-64k-seq", davinci_poc_erase_64k_cmdtbl),
	[POC_ERASE_EXIT_SEQ] = SEQINFO_INIT("poc-erase-exit-seq", davinci_poc_erase_exit_cmdtbl),
#endif

	/* poc write */
	[POC_WRITE_ENTER_SEQ] = SEQINFO_INIT("poc-wr-enter-seq", davinci_poc_wr_enter_cmdtbl),
	[POC_WRITE_DAT_SEQ] = SEQINFO_INIT("poc-wr-dat-seq", davinci_poc_wr_dat_cmdtbl),
	[POC_WRITE_EXIT_SEQ] = SEQINFO_INIT("poc-wr-exit-seq", davinci_poc_wr_exit_cmdtbl),

	/* poc read */
	[POC_READ_ENTER_SEQ] = SEQINFO_INIT("poc-rd-enter-seq", davinci_poc_rd_enter_cmdtbl),
	[POC_READ_DAT_SEQ] = SEQINFO_INIT("poc-rd-dat-seq", davinci_poc_rd_dat_cmdtbl),
	[POC_READ_EXIT_SEQ] = SEQINFO_INIT("poc-rd-exit-seq", davinci_poc_rd_exit_cmdtbl),
#ifdef CONFIG_SUPPORT_POC_SPI
	[POC_SPI_INIT_SEQ] = SEQINFO_INIT("poc-spi-init-seq", davinci_poc_spi_init_cmdtbl),
	[POC_SPI_READ_SEQ] = SEQINFO_INIT("poc-spi-read-seq", davinci_poc_spi_read_cmdtbl),
	[POC_SPI_ERASE_4K_SEQ] = SEQINFO_INIT("poc-spi-erase-4k-seq", davinci_poc_spi_erase_4k_cmdtbl),
	[POC_SPI_ERASE_32K_SEQ] = SEQINFO_INIT("poc-spi-erase-4k-seq", davinci_poc_spi_erase_32k_cmdtbl),
	[POC_SPI_ERASE_64K_SEQ] = SEQINFO_INIT("poc-spi-erase-32k-seq", davinci_poc_spi_erase_64k_cmdtbl),
	[POC_SPI_WRITE_SEQ] = SEQINFO_INIT("poc-spi-write-seq", davinci_poc_spi_write_cmdtbl),
	[POC_SPI_STATUS_SEQ] = SEQINFO_INIT("poc-spi-status-seq", davinci_poc_spi_status_cmdtbl),
#endif
};

/* partition consists of DATA, CHECKSUM and MAGICNUM */
static struct poc_partition davinci_poc_partition[] = {
	[POC_IMG_PARTITION] = {
		.name = "image",
		.addr = DAVINCI_POC_IMG_ADDR,
		.size = DAVINCI_POC_IMG_SIZE,
		.need_preload = false
	},
#ifdef CONFIG_SUPPORT_DIM_FLASH
	[POC_DIM_PARTITION] = {
		.name = "dimming",
		.addr = DAVINCI_POC_DIM_DATA_ADDR,
		.size = DAVINCI_POC_DIM_TOTAL_SIZE,
		.data_addr = DAVINCI_POC_DIM_DATA_ADDR,
		.data_size = DAVINCI_POC_DIM_DATA_SIZE,
		.checksum_addr = DAVINCI_POC_DIM_CHECKSUM_ADDR,
		.checksum_size = DAVINCI_POC_DIM_CHECKSUM_SIZE,
		.magicnum_addr = DAVINCI_POC_DIM_MAGICNUM_ADDR,
		.magicnum_size = DAVINCI_POC_DIM_MAGICNUM_SIZE,
		.need_preload = false,
		.magicnum = 1,
	},
	[POC_MTP_PARTITION] = {
		.name = "mtp",
		.addr = DAVINCI_POC_MTP_DATA_ADDR,
		.size = DAVINCI_POC_MTP_TOTAL_SIZE,
		.data_addr = DAVINCI_POC_MTP_DATA_ADDR,
		.data_size = DAVINCI_POC_MTP_DATA_SIZE,
		.checksum_addr = DAVINCI_POC_MTP_CHECKSUM_ADDR,
		.checksum_size = DAVINCI_POC_MTP_CHECKSUM_SIZE,
		.magicnum_addr = 0,
		.magicnum_size = 0,
		.need_preload = false,
	},
#endif
	[POC_MCD_PARTITION] = {
		.name = "mcd",
		.addr = DAVINCI_POC_MCD_ADDR,
		.size = DAVINCI_POC_MCD_SIZE,
		.need_preload = false
	},
};

static struct panel_poc_data s6e3ha9_davinci_poc_data = {
	.version = 2,
	.seqtbl = davinci_poc_seqtbl,
	.nr_seqtbl = ARRAY_SIZE(davinci_poc_seqtbl),
	.maptbl = davinci_poc_maptbl,
	.nr_maptbl = ARRAY_SIZE(davinci_poc_maptbl),
	.partition = davinci_poc_partition,
	.nr_partition = ARRAY_SIZE(davinci_poc_partition),
	.wdata_len = 256,
#ifdef CONFIG_SUPPORT_POC_SPI
	.spi_wdata_len = 256,
#endif
};
#endif /* __S6E3HA9_DAVINCI_PANEL_POC_H__ */
