/*
 * Copyright(c) 2007 Atheros Corporation. All rights reserved.
 *
 * Derived from Intel e1000 driver
 * Copyright(c) 1999 - 2005 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59
 * Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef _ATL1E_HW_H_
#define _ATL1E_HW_H_

#include "at_osdep.h"

#define _AT_ATTRIB_PACK_    __attribute__ ((packed))

struct atl1e_adapter;
struct atl1e_hw;

/* function prototype */

s32 atl1e_reset_hw(struct atl1e_hw* hw);
s32 atl1e_read_mac_addr(struct atl1e_hw* hw);
s32 atl1e_init_hw(struct atl1e_hw* hw);
s32 atl1e_phy_setup_autoneg_adv(struct atl1e_hw *hw);
s32 atl1e_phy_commit(struct atl1e_hw *hw);
s32 atl1e_get_speed_and_duplex(struct atl1e_hw *hw, u16 *speed, u16 *duplex);
u32 atl1e_auto_get_fc(struct atl1e_adapter* adapter, u16 duplex);
u32 atl1e_hash_mc_addr(struct atl1e_hw *hw, u8 *mc_addr);
void atl1e_hash_set(struct atl1e_hw *hw, u32 hash_value);
s32 atl1e_read_phy_reg(struct atl1e_hw *hw, u16 reg_addr, u16 *phy_data);
s32 atl1e_write_phy_reg(struct atl1e_hw *hw, u32 reg_addr, u16 phy_data);
void atl1e_read_pci_cfg(struct atl1e_hw*  hw, u32 reg, u16 *value);
void atl1e_write_pci_cfg(struct atl1e_hw* hw, u32 reg, u16 *value); 
s32 atl1e_validate_mdi_setting(struct atl1e_hw* hw);
void set_mac_addr(struct atl1e_hw* hw);
int get_permanent_address(struct atl1e_hw* hw);
boolean_t read_eeprom(struct atl1e_hw* hw, u32 Offset, u32* pValue);
boolean_t write_eeprom(struct atl1e_hw* hw, u32 offset, u32 value);
s32 atl1e_phy_enter_power_saving(struct atl1e_hw* hw);
s32 atl1e_phy_leave_power_saving(struct atl1e_hw* hw);
s32 atl1e_phy_init(struct atl1e_hw* hw);
int check_eeprom_exist(struct atl1e_hw* hw);
void atl1e_force_ps(struct atl1e_hw* hw);
s32 atl1e_restart_autoneg(struct atl1e_hw *hw);
int atl1e_phy_ctrl_link_chg_pre(struct atl1e_hw *hw);

/* register definition */

/* register definition */
#define REG_PM_CTRLSTAT             0x44

#define REG_PCIE_CAP_LIST           0x58

#define REG_DEVICE_CAP              0x5C
#define     DEVICE_CAP_MAX_PAYLOAD_MASK     0x7
#define     DEVICE_CAP_MAX_PAYLOAD_SHIFT    0

#define REG_DEVICE_CTRL             0x60
#define     DEVICE_CTRL_MAX_PAYLOAD_MASK    0x7
#define     DEVICE_CTRL_MAX_PAYLOAD_SHIFT   5
#define     DEVICE_CTRL_MAX_RREQ_SZ_MASK    0x7
#define     DEVICE_CTRL_MAX_RREQ_SZ_SHIFT   12

#define REG_LINK_CAP                0x64
#define     LINK_CAP_ASPM_SUP_MASK          0x3
#define     LINK_CAP_ASPM_SUP_SHIFT         10

#define REG_LINK_CTRL               0x68
#define     LINK_CTRL_ASPM_MASK             0x3
#define     LINK_CTRL_ASPM_SHIFT            0

#define REG_VPD_CAP                 0x6C
#define     VPD_CAP_ID_MASK                 0xff
#define     VPD_CAP_ID_SHIFT                0
#define     VPD_CAP_NEXT_PTR_MASK           0xFF
#define     VPD_CAP_NEXT_PTR_SHIFT          8
#define     VPD_CAP_VPD_ADDR_MASK           0x7FFF
#define     VPD_CAP_VPD_ADDR_SHIFT          16
#define     VPD_CAP_VPD_FLAG                0x80000000

#define REG_VPD_DATA                0x70

#define REG_SPI_FLASH_CTRL          0x200
#define     SPI_FLASH_CTRL_STS_NON_RDY      0x1
#define     SPI_FLASH_CTRL_STS_WEN          0x2
#define     SPI_FLASH_CTRL_STS_WPEN         0x80
#define     SPI_FLASH_CTRL_DEV_STS_MASK     0xFF
#define     SPI_FLASH_CTRL_DEV_STS_SHIFT    0
#define     SPI_FLASH_CTRL_INS_MASK         0x7
#define     SPI_FLASH_CTRL_INS_SHIFT        8
#define     SPI_FLASH_CTRL_START            0x800
#define     SPI_FLASH_CTRL_EN_VPD           0x2000
#define     SPI_FLASH_CTRL_LDSTART          0x8000
#define     SPI_FLASH_CTRL_CS_HI_MASK       0x3
#define     SPI_FLASH_CTRL_CS_HI_SHIFT      16
#define     SPI_FLASH_CTRL_CS_HOLD_MASK     0x3
#define     SPI_FLASH_CTRL_CS_HOLD_SHIFT    18
#define     SPI_FLASH_CTRL_CLK_LO_MASK      0x3
#define     SPI_FLASH_CTRL_CLK_LO_SHIFT     20
#define     SPI_FLASH_CTRL_CLK_HI_MASK      0x3
#define     SPI_FLASH_CTRL_CLK_HI_SHIFT     22
#define     SPI_FLASH_CTRL_CS_SETUP_MASK    0x3
#define     SPI_FLASH_CTRL_CS_SETUP_SHIFT   24
#define     SPI_FLASH_CTRL_EROM_PGSZ_MASK   0x3
#define     SPI_FLASH_CTRL_EROM_PGSZ_SHIFT  26
#define     SPI_FLASH_CTRL_WAIT_READY       0x10000000

#define REG_SPI_ADDR                0x204

#define REG_SPI_DATA                0x208

#define REG_SPI_FLASH_CONFIG        0x20C
#define     SPI_FLASH_CONFIG_LD_ADDR_MASK   0xFFFFFF
#define     SPI_FLASH_CONFIG_LD_ADDR_SHIFT  0
#define     SPI_FLASH_CONFIG_VPD_ADDR_MASK  0x3
#define     SPI_FLASH_CONFIG_VPD_ADDR_SHIFT 24
#define     SPI_FLASH_CONFIG_LD_EXIST       0x4000000


#define REG_SPI_FLASH_OP_PROGRAM    0x210
#define REG_SPI_FLASH_OP_SC_ERASE   0x211
#define REG_SPI_FLASH_OP_CHIP_ERASE 0x212
#define REG_SPI_FLASH_OP_RDID       0x213
#define REG_SPI_FLASH_OP_WREN       0x214
#define REG_SPI_FLASH_OP_RDSR       0x215
#define REG_SPI_FLASH_OP_WRSR       0x216
#define REG_SPI_FLASH_OP_READ       0x217

#define REG_TWSI_CTRL               0x218
#define     TWSI_CTRL_LD_OFFSET_MASK        0xFF
#define     TWSI_CTRL_LD_OFFSET_SHIFT       0
#define     TWSI_CTRL_LD_SLV_ADDR_MASK      0x7
#define     TWSI_CTRL_LD_SLV_ADDR_SHIFT     8
#define     TWSI_CTRL_SW_LDSTART            0x800
#define     TWSI_CTRL_HW_LDSTART            0x1000
#define     TWSI_CTRL_SMB_SLV_ADDR_MASK     0x0x7F
#define     TWSI_CTRL_SMB_SLV_ADDR_SHIFT    15
#define     TWSI_CTRL_LD_EXIST              0x400000
#define     TWSI_CTRL_READ_FREQ_SEL_MASK    0x3
#define     TWSI_CTRL_READ_FREQ_SEL_SHIFT   23
#define     TWSI_CTRL_FREQ_SEL_100K         0
#define     TWSI_CTRL_FREQ_SEL_200K         1
#define     TWSI_CTRL_FREQ_SEL_300K         2
#define     TWSI_CTRL_FREQ_SEL_400K         3
#define     TWSI_CTRL_SMB_SLV_ADDR
#define     TWSI_CTRL_WRITE_FREQ_SEL_MASK   0x3
#define     TWSI_CTRL_WRITE_FREQ_SEL_SHIFT  24

#define REG_PCIE_DEV_MISC_CTRL      0x21C
#define     PCIE_DEV_MISC_CTRL_EXT_PIPE     0x2
#define     PCIE_DEV_MISC_CTRL_RETRY_BUFDIS 0x1
#define     PCIE_DEV_MISC_CTRL_SPIROM_EXIST 0x4
#define     PCIE_DEV_MISC_CTRL_SERDES_ENDIAN    0x8
#define     PCIE_DEV_MISC_CTRL_SERDES_SEL_DIN   0x10

#define REG_PCIE_PHYMISC            0x1000
#define     PCIE_PHYMISC_FORCE_RCV_DET	    0x4

#define REG_PCIE_PM_CTRL          0x12F8
#define     PCIE_PM_EN_SDES                 0x00000001
#define     PCIE_PM_EN_PBER                 0x00000002
#define     PCIE_PM_EN_CLK_REQ              0x00000004
#define     PCIE_PM_EN_ASPM_L1              0x00000008
#define     PCIE_PM_EN_SERDES_L1            0x00000010
#define     PCIE_PM_EN_SERDES_PLL_L1        0x00000020
#define     PCIE_PM_EN_SERDES_RX_L1         0x00000040
#define     PCIE_PM_EN_SERDES_BUFS_RX_L1    0x00000080
#define     PCIE_PM_L0S_ENTRY_TIMER_MASK    0xF
#define     PCIE_PM_L0S_ENTRY_TIMER_SHIFT   8
#define     PCIE_PM_EN_ASPM_L0S             0x00001000
#define     PCIE_PM_EN_CLK_SWH_L1           0x00002000
#define     PCIE_PM_PWM_VER                 0x00004000
#define     PCIE_PM_PCIE_RCVR_CTRL          0x00008000
#define     PCIE_PM_L1_ENTRY_TIMER_MASK     0xF
#define     PCIE_PM_L1_ENTRY_TIMER_SHIFT    16
#define     PCIE_PM_PM_REQ_TIMER_MASK       0xF
#define     PCIE_PM_PM_REQ_TIMER_SHIFT      20
#define     PCIE_PM_LCKDET_TIMER_MASK       0xF
#define     PCIE_PM_LCKDET_TIMER_SHIFT      24

#define REG_LTSSM_TEST_MODE         0x12FC
#define     LTSSM_TEST_MODE_DEF             0xE000

// Selene Master Control Register
#define REG_MASTER_CTRL             0x1400
#define     MASTER_CTRL_SOFT_RST            0x1    
#define     MASTER_CTRL_MTIMER_EN           0x2 
#define     MASTER_CTRL_ITIMER_EN           0x4
#define     MASTER_CTRL_MANUAL_INT          0x8 
#define     MASTER_CTRL_ITIMER2_EN          0x20
#define     MASTER_CTRL_INT_RDCLR           0x40
#define     MASTER_CTRL_LED_MODE			0x200
#define     MASTER_CTRL_REV_NUM_SHIFT       16     
#define     MASTER_CTRL_REV_NUM_MASK        0xff
#define     MASTER_CTRL_DEV_ID_SHIFT        24    
#define     MASTER_CTRL_DEV_ID_MASK         0xff

// Timer Initial Value Register
#define REG_MANUAL_TIMER_INIT       0x1404   


// IRQ ModeratorTimer Initial Value Register
#define REG_IRQ_MODU_TIMER_INIT     0x1408   // w
#define REG_IRQ_MODU_TIMER2_INIT    0x140A   // w   


#define REG_GPHY_CTRL               0x140C
#define     GPHY_CTRL_EXT_RESET         1
#define     GPHY_CTRL_PIPE_MOD          2
#define     GPHY_CTRL_TEST_MODE_MASK    3
#define     GPHY_CTRL_TEST_MODE_SHIFT   2
#define     GPHY_CTRL_BERT_START        0x10
#define     GPHY_CTRL_GATE_25M_EN       0x20
#define     GPHY_CTRL_LPW_EXIT          0x40
#define     GPHY_CTRL_PHY_IDDQ          0x80
#define     GPHY_CTRL_PHY_IDDQ_DIS      0x100
#define     GPHY_CTRL_PCLK_SEL_DIS      0x200
#define     GPHY_CTRL_HIB_EN            0x400
#define     GPHY_CTRL_HIB_PULSE         0x800
#define     GPHY_CTRL_SEL_ANA_RST       0x1000
#define     GPHY_CTRL_PHY_PLL_ON        0x2000
#define     GPHY_CTRL_PWDOWN_HW			0x4000
#define     GPHY_CTRL_DEFAULT				(\
					GPHY_CTRL_SEL_ANA_RST	|\
					GPHY_CTRL_HIB_PULSE		|\
					GPHY_CTRL_HIB_EN		)

#define     GPHY_CTRL_PW_WOL_DIS			(\
					GPHY_CTRL_SEL_ANA_RST	|\
					GPHY_CTRL_HIB_PULSE		|\
					GPHY_CTRL_HIB_EN		|\
					GPHY_CTRL_PWDOWN_HW		|\
					GPHY_CTRL_PCLK_SEL_DIS	|\
					GPHY_CTRL_PHY_IDDQ		)



// IRQ Anti-Lost Timer Initial Value Register
//#define REG_IRQ_CLR_TIMER           0x140c                   // Maximum allowance for software to clear the interrupt.
// IRQ Anti-Lost Timer Initial Value Register
#define REG_CMBDISDMA_TIMER         0x140E    
  
  
  
// Block IDLE Status Register
#define REG_IDLE_STATUS             0x1410
#define     IDLE_STATUS_RXMAC               1                   // 1: RXMAC state machine is in non-IDLE state. 0: RXMAC is idling
#define     IDLE_STATUS_TXMAC               2                   // 1: TXMAC state machine is in non-IDLE state. 0: TXMAC is idling
#define     IDLE_STATUS_RXQ                 4                   // 1: RXQ state machine is in non-IDLE state.   0: RXQ is idling
#define     IDLE_STATUS_TXQ                 8                   // 1: TXQ state machine is in non-IDLE state.   0: TXQ is idling
#define     IDLE_STATUS_DMAR                0x10                // 1: DMAR state machine is in non-IDLE state.  0: DMAR is idling
#define     IDLE_STATUS_DMAW                0x20                // 1: DMAW state machine is in non-IDLE state.  0: DMAW is idling
#define     IDLE_STATUS_SMB                 0x40                // 1: SMB state machine is in non-IDLE state.   0: SMB is idling
#define     IDLE_STATUS_CMB                 0x80                // 1: CMB state machine is in non-IDLE state.   0: CMB is idling

// MDIO Control Register
#define REG_MDIO_CTRL               0x1414
#define     MDIO_DATA_MASK                  0xffff                // On MDIO write, the 16-bit control data to write to PHY MII management register;
#define     MDIO_DATA_SHIFT                 0                   // On MDIO read, the 16-bit status data that was read from the PHY MII management register.
#define     MDIO_REG_ADDR_MASK              0x1f                // MDIO register address
#define     MDIO_REG_ADDR_SHIFT             16
#define     MDIO_RW                         0x200000            // 1: read, 0: write
#define     MDIO_SUP_PREAMBLE               0x400000            // Suppress preamble
#define     MDIO_START                      0x800000            // Write 1 to initiate the MDIO master. And this bit is self cleared after one cycle.
#define     MDIO_CLK_SEL_SHIFT              24
#define     MDIO_CLK_25_4                   0
#define     MDIO_CLK_25_6                   2
#define     MDIO_CLK_25_8                   3
#define     MDIO_CLK_25_10                  4
#define     MDIO_CLK_25_14                  5
#define     MDIO_CLK_25_20                  6
#define     MDIO_CLK_25_28                  7
#define     MDIO_BUSY                       0x8000000       
#define     MDIO_AP_EN                      0x10000000
#define MDIO_WAIT_TIMES                                     10                  

// MII PHY Status Register
#define REG_PHY_STATUS              0x1418   
#define     PHY_STATUS_100M				0x20000                
#define     PHY_STATUS_EMI_CA				0x40000

// BIST Control and Status Register0 (for the Packet Memory)
#define REG_BIST0_CTRL              0x141c                   
#define     BIST0_NOW                       0x1             // 1: To trigger BIST0 logic. This bit stays high during the 
				// BIST process and reset to zero when BIST is done
#define     BIST0_SRAM_FAIL                 0x2             // 1: The SRAM failure is un-repairable because it has address 
				// decoder failure or more than 1 cell stuck-to-x failure.  
#define     BIST0_FUSE_FLAG                 0x4             // 1: Indicating one cell has been fixed

// BIST Control and Status Register1(for the retry buffer of PCI Express)
#define REG_BIST1_CTRL              0x1420                   
#define     BIST1_NOW                       0x1             // 1: To trigger BIST0 logic. This bit stays high during the 
				// BIST process and reset to zero when BIST is done
#define     BIST1_SRAM_FAIL                 0x2             // 1: The SRAM failure is un-repairable because it has address 
				// decoder failure or more than 1 cell stuck-to-x failure.                                                      
#define     BIST1_FUSE_FLAG                 0x4
               
// SerDes Lock Detect Control and Status Register
#define REG_SERDES_LOCK             0x1424
#define     SERDES_LOCK_DETECT              1                   // 1: SerDes lock detected . This signal comes from Analog SerDes.
#define     SERDES_LOCK_DETECT_EN           2                   // 1: Enable SerDes Lock detect function.
                                
// MAC Control Register                         
#define REG_MAC_CTRL                0x1480                  
#define     MAC_CTRL_TX_EN                  1                   // 1: Transmit Enable
#define     MAC_CTRL_RX_EN                  2                   // 1: Receive Enable
#define     MAC_CTRL_TX_FLOW                4                   // 1: Transmit Flow Control Enable
#define     MAC_CTRL_RX_FLOW                8                   // 1: Receive Flow Control Enable
#define     MAC_CTRL_LOOPBACK               0x10                // 1: Loop back at G/MII Interface
#define     MAC_CTRL_DUPLX                  0x20                // 1: Full-duplex mode  0: Half-duplex mode
#define     MAC_CTRL_ADD_CRC                0x40                // 1: Instruct MAC to attach CRC on all egress Ethernet frames
#define     MAC_CTRL_PAD                    0x80                // 1: Instruct MAC to pad short frames to 60-bytes, and then attach CRC. This bit has higher priority over CRC_EN
#define     MAC_CTRL_LENCHK                 0x100               // 1: Instruct MAC to check if length field matches the real packet length.
#define     MAC_CTRL_HUGE_EN                0x200               // 1: receive Jumbo frame enable
#define     MAC_CTRL_PRMLEN_SHIFT           10                  // Preamble length, it?��s 0x07 by standard
#define     MAC_CTRL_PRMLEN_MASK            0xf                 
#define     MAC_CTRL_RMV_VLAN               0x4000              // 1: to remove VLAN Tag automatically from all receive packets
#define     MAC_CTRL_PROMIS_EN              0x8000              // 1: Promiscuous Mode Enable
#define     MAC_CTRL_TX_PAUSE               0x10000             // 1: transmit test pause
#define     MAC_CTRL_SCNT                   0x20000             // 1: shortcut slot time counter
#define     MAC_CTRL_SRST_TX                0x40000             // 1: synchronized reset Transmit MAC module
#define     MAC_CTRL_TX_SIMURST             0x80000             // 1: transmit simulation reset
#define     MAC_CTRL_SPEED_SHIFT            20                  // 2?��b10: gigabit    2?��b01:10M/100M
#define     MAC_CTRL_SPEED_MASK             0x300000
#define     MAC_CTRL_SPEED_1000             2
#define     MAC_CTRL_SPEED_10_100           1
#define     MAC_CTRL_DBG_TX_BKPRESURE       0x400000            // 1: transmit maximum backoff (half-duplex test bit)
#define     MAC_CTRL_TX_HUGE                0x800000            // 1: transmit huge enable
#define     MAC_CTRL_RX_CHKSUM_EN           0x1000000           // 1: RX checksum enable
#define     MAC_CTRL_MC_ALL_EN              0x2000000           // 1: upload all multicast frame without error to system 
#define     MAC_CTRL_BC_EN                  0x4000000           // 1: upload all broadcast frame without error to system
#define     MAC_CTRL_DBG                    0x8000000           // 1: upload all received frame to system (Debug Mode)

// MAC IPG/IFG Control Register                 
#define REG_MAC_IPG_IFG             0x1484                   
#define     MAC_IPG_IFG_IPGT_SHIFT          0                   // Desired back to back inter-packet gap. The default is 96-bit time.
#define     MAC_IPG_IFG_IPGT_MASK           0x7f
#define     MAC_IPG_IFG_MIFG_SHIFT          8                   // Minimum number of IFG to enforce in between RX frames.
#define     MAC_IPG_IFG_MIFG_MASK           0xff                // Frame gap below such IFP is dropped.
#define     MAC_IPG_IFG_IPGR1_SHIFT         16                  // 64bit Carrier-Sense window
#define     MAC_IPG_IFG_IPGR1_MASK          0x7f                // 
#define     MAC_IPG_IFG_IPGR2_SHIFT         24                  // 96-bit IPG window
#define     MAC_IPG_IFG_IPGR2_MASK          0x7f

// MAC STATION ADDRESS                          
#define REG_MAC_STA_ADDR            0x1488

// Hash table for multicast address
#define REG_RX_HASH_TABLE           0x1490


// MAC Half-Duplex Control Register 
#define REG_MAC_HALF_DUPLX_CTRL     0x1498                   
#define     MAC_HALF_DUPLX_CTRL_LCOL_SHIFT   0                  // Collision Window.
#define     MAC_HALF_DUPLX_CTRL_LCOL_MASK    0x3ff
#define     MAC_HALF_DUPLX_CTRL_RETRY_SHIFT  12                 // Retransmission maximum, afterwards the packet will be discarded.
#define     MAC_HALF_DUPLX_CTRL_RETRY_MASK   0xf
#define     MAC_HALF_DUPLX_CTRL_EXC_DEF_EN   0x10000            // 1: Allow the transmission of a packet which has been excessively deferred
#define     MAC_HALF_DUPLX_CTRL_NO_BACK_C    0x20000            // 1: No back-off on collision, immediately start the retransmission.
#define     MAC_HALF_DUPLX_CTRL_NO_BACK_P    0x40000            // 1: No back-off on backpressure, immediately start the transmission after back pressure
#define     MAC_HALF_DUPLX_CTRL_ABEBE        0x80000            // 1: Alternative Binary Exponential Back-off Enabled
#define     MAC_HALF_DUPLX_CTRL_ABEBT_SHIFT  20                 // Maximum binary exponential number.
#define     MAC_HALF_DUPLX_CTRL_ABEBT_MASK   0xf
#define     MAC_HALF_DUPLX_CTRL_JAMIPG_SHIFT 24                 // IPG to start JAM for collision based flow control in half-duplex 
#define     MAC_HALF_DUPLX_CTRL_JAMIPG_MASK  0xf                // mode. In unit of 8-bit time.

// Maximum Frame Length Control Register   
#define REG_MTU                     0x149c                   

// Wake-On-Lan control register
#define REG_WOL_CTRL                0x14a0                   
#define     WOL_PATTERN_EN                  0x00000001
#define     WOL_PATTERN_PME_EN              0x00000002
#define     WOL_MAGIC_EN                    0x00000004
#define     WOL_MAGIC_PME_EN                0x00000008
#define     WOL_LINK_CHG_EN                 0x00000010
#define     WOL_LINK_CHG_PME_EN             0x00000020
#define     WOL_PATTERN_ST                  0x00000100
#define     WOL_MAGIC_ST                    0x00000200
#define     WOL_LINKCHG_ST                  0x00000400
#define     WOL_CLK_SWITCH_EN               0x00008000
#define     WOL_PT0_EN                      0x00010000
#define     WOL_PT1_EN                      0x00020000
#define     WOL_PT2_EN                      0x00040000
#define     WOL_PT3_EN                      0x00080000
#define     WOL_PT4_EN                      0x00100000
#define     WOL_PT5_EN                      0x00200000
#define     WOL_PT6_EN                      0x00400000
// WOL Length ( 2 DWORD )
#define REG_WOL_PATTERN_LEN         0x14a4
#define     WOL_PT_LEN_MASK                 0x7f
#define     WOL_PT0_LEN_SHIFT               0
#define     WOL_PT1_LEN_SHIFT               8
#define     WOL_PT2_LEN_SHIFT               16
#define     WOL_PT3_LEN_SHIFT               24
#define     WOL_PT4_LEN_SHIFT               0
#define     WOL_PT5_LEN_SHIFT               8
#define     WOL_PT6_LEN_SHIFT               16
	       
// Internal SRAM Partition Register 
#define REG_SRAM_TRD_ADDR                       0x1518
#define REG_SRAM_TRD_LEN                        0x151C
#define REG_SRAM_RXF_ADDR                       0x1520
#define REG_SRAM_RXF_LEN                        0x1524
#define REG_SRAM_TXF_ADDR                       0x1528
#define REG_SRAM_TXF_LEN                        0x152C
#define REG_SRAM_TCPH_ADDR                      0x1530
#define REG_SRAM_PKTH_ADDR                      0x1532

// Load Ptr Register 
#define REG_LOAD_PTR                0x1534  // Software sets this bit after the initialization of the head and tail    
				// addresses of all descriptors, as well as the following descriptor                                
				// control register, which triggers each function block to load the head                                                          
				// pointer to prepare for the operation. This bit is then self-cleared      
				// after one cycle.                                                        
//  Descriptor Control register  
#define REG_RXF3_BASE_ADDR_HI           0x153C

//  Descriptor Control register                                     
#define REG_DESC_BASE_ADDR_HI           0x1540   
#define REG_HOST_RXF0_PAGE0_LO          0x1544
#define REG_HOST_RXF0_PAGE1_LO          0x1548
#define REG_TPD_BASE_ADDR_LO            0x154C
#define REG_RXF1_BASE_ADDR_HI           0x1550
#define REG_RXF2_BASE_ADDR_HI           0x1554
#define REG_HOST_RXFPAGE_SIZE           0x1558
#define REG_TPD_RING_SIZE               0x155C
// RSS about
#define REG_RSS_KEY0                    0x14B0
#define REG_RSS_KEY1                    0x14B4
#define REG_RSS_KEY2                    0x14B8
#define REG_RSS_KEY3                    0x14BC
#define REG_RSS_KEY4                    0x14C0
#define REG_RSS_KEY5                    0x14C4
#define REG_RSS_KEY6                    0x14C8
#define REG_RSS_KEY7                    0x14CC
#define REG_RSS_KEY8                    0x14D0
#define REG_RSS_KEY9                    0x14D4
#define REG_IDT_TABLE4                  0x14E0
#define REG_IDT_TABLE5                  0x14E4
#define REG_IDT_TABLE6                  0x14E8
#define REG_IDT_TABLE7                  0x14EC
#define REG_IDT_TABLE0                  0x1560
#define REG_IDT_TABLE1                  0x1564
#define REG_IDT_TABLE2                  0x1568
#define REG_IDT_TABLE3                  0x156C
#define REG_IDT_TABLE                   REG_IDT_TABLE0
#define REG_RSS_HASH_VALUE              0x1570
#define REG_RSS_HASH_FLAG               0x1574
#define REG_BASE_CPU_NUMBER             0x157C


// TXQ Control Register                                                                                                                    
#define REG_TXQ_CTRL                0x1580       
#define     TXQ_CTRL_NUM_TPD_BURST_MASK     0xF
#define     TXQ_CTRL_NUM_TPD_BURST_SHIFT    0
#define     TXQ_CTRL_EN                     0x20                // 1: Enable TXQ
#define     TXQ_CTRL_ENH_MODE               0x40                // Performance enhancement mode, in which up to two back-to-back DMA read commands might be dispatched.
#define     TXQ_CTRL_TXF_BURST_NUM_SHIFT    16                  // Number of data byte to read in a cache-aligned burst. Each SRAM entry is 8-byte in length.
#define     TXQ_CTRL_TXF_BURST_NUM_MASK     0xffff  

// Jumbo packet Threshold for task offload
#define REG_TX_EARLY_TH                     0x1584              // Jumbo frame threshold in QWORD unit. Packet greater than 
                                                                // JUMBO_TASK_OFFLOAD_THRESHOLD will not be task offloaded.
#define     TX_TX_EARLY_TH_MASK             0x7ff
#define     TX_TX_EARLY_TH_SHIFT            0
                

// RXQ Control Register
#define REG_RXQ_CTRL                0x15A0
#define         RXQ_CTRL_PBA_ALIGN_32                   0   /* rx-packet alignment */
#define         RXQ_CTRL_PBA_ALIGN_64                   1
#define         RXQ_CTRL_PBA_ALIGN_128                  2
#define         RXQ_CTRL_PBA_ALIGN_256                  3
#define         RXQ_CTRL_Q1_EN							0x10
#define         RXQ_CTRL_Q2_EN							0x20
#define         RXQ_CTRL_Q3_EN							0x40
#define         RXQ_CTRL_IPV6_XSUM_VERIFY_EN			0x80
#define         RXQ_CTRL_HASH_TLEN_SHIFT                8
#define         RXQ_CTRL_HASH_TLEN_MASK                 0xFF
#define         RXQ_CTRL_HASH_TYPE_IPV4                 0x10000
#define         RXQ_CTRL_HASH_TYPE_IPV4_TCP             0x20000
#define         RXQ_CTRL_HASH_TYPE_IPV6                 0x40000
#define         RXQ_CTRL_HASH_TYPE_IPV6_TCP             0x80000
#define         RXQ_CTRL_RSS_MODE_DISABLE               0
#define         RXQ_CTRL_RSS_MODE_SQSINT                0x4000000
#define         RXQ_CTRL_RSS_MODE_MQUESINT              0x8000000
#define         RXQ_CTRL_RSS_MODE_MQUEMINT              0xC000000
#define         RXQ_CTRL_NIP_QUEUE_SEL_TBL              0x10000000
#define         RXQ_CTRL_HASH_ENABLE                    0x20000000
#define         RXQ_CTRL_CUT_THRU_EN                    0x40000000
#define         RXQ_CTRL_EN                             0x80000000
 
// Rx jumbo packet threshold and rrd  retirement timer         
#define REG_RXQ_JMBOSZ_RRDTIM       0x15A4
#define         RXQ_JMBOSZ_TH_MASK          0x7ff               // Jumbo packet threshold for non-VLAN packet, in QWORD (64-bit) unit. When the packet 
                                // length greater than or equal to this value, RXQ shall start cut-through forwarding of the received packet.                   
#define         RXQ_JMBOSZ_TH_SHIFT         0                                   // RRD retirement timer. Decrement by 1 after every 512ns passes.                                                                               
#define         RXQ_JMBO_LKAH_MASK          0xf
#define         RXQ_JMBO_LKAH_SHIFT         11

// RXF flow control register
#define REG_RXQ_RXF_PAUSE_THRESH    0x15A8       
#define     RXQ_RXF_PAUSE_TH_HI_SHIFT       0
#define     RXQ_RXF_PAUSE_TH_HI_MASK        0xfff
#define     RXQ_RXF_PAUSE_TH_LO_SHIFT       16  
#define     RXQ_RXF_PAUSE_TH_LO_MASK        0xfff   


// DMA Engine Control Register
#define REG_DMA_CTRL                0x15C0                   
#define     DMA_CTRL_DMAR_IN_ORDER          0x1
#define     DMA_CTRL_DMAR_ENH_ORDER         0x2
#define     DMA_CTRL_DMAR_OUT_ORDER         0x4
#define     DMA_CTRL_RCB_VALUE              0x8
#define     DMA_CTRL_DMAR_BURST_LEN_SHIFT   4
#define     DMA_CTRL_DMAR_BURST_LEN_MASK    7
#define     DMA_CTRL_DMAW_BURST_LEN_SHIFT   7
#define     DMA_CTRL_DMAW_BURST_LEN_MASK    7
#define     DMA_CTRL_DMAR_REQ_PRI           0x400
#define     DMA_CTRL_DMAR_DLY_CNT_MASK      0x1F
#define     DMA_CTRL_DMAR_DLY_CNT_SHIFT     11
#define     DMA_CTRL_DMAW_DLY_CNT_MASK      0xF
#define     DMA_CTRL_DMAW_DLY_CNT_SHIFT     16
#define     DMA_CTRL_TXCMB_EN               0x100000
#define     DMA_CTRL_RXCMB_EN				0x200000	


// CMB/SMB Control Register
#define REG_SMB_STAT_TIMER                      0x15C4
#define REG_TRIG_RRD_THRESH                     0x15CA  // w
#define REG_TRIG_TPD_THRESH                     0x15C8  // w
#define REG_TRIG_TXTIMER                        0x15CC  // w
#define REG_TRIG_RXTIMER                        0x15CE  // w

// HOST RXF Page 1,2,3 address
#define REG_HOST_RXF1_PAGE0_LO                  0x15D0
#define REG_HOST_RXF1_PAGE1_LO                  0x15D4
#define REG_HOST_RXF2_PAGE0_LO                  0x15D8
#define REG_HOST_RXF2_PAGE1_LO                  0x15DC
#define REG_HOST_RXF3_PAGE0_LO                  0x15E0
#define REG_HOST_RXF3_PAGE1_LO                  0x15E4

// Mail box
#define REG_MB_RXF1_RADDR                       0x15B4
#define REG_MB_RXF2_RADDR                       0x15B8
#define REG_MB_RXF3_RADDR                       0x15BC
#define REG_MB_TPD_PROD_IDX                     0x15F0

// RXF-Page 0-3  PageNo & Valid bit
#define REG_HOST_RXF0_PAGE0_VLD     0x15F4
#define     HOST_RXF_VALID                  1
#define     HOST_RXF_PAGENO_SHIFT           1
#define     HOST_RXF_PAGENO_MASK            0x7F
#define REG_HOST_RXF0_PAGE1_VLD     0x15F5
#define REG_HOST_RXF1_PAGE0_VLD     0x15F6
#define REG_HOST_RXF1_PAGE1_VLD     0x15F7
#define REG_HOST_RXF2_PAGE0_VLD     0x15F8
#define REG_HOST_RXF2_PAGE1_VLD     0x15F9
#define REG_HOST_RXF3_PAGE0_VLD     0x15FA
#define REG_HOST_RXF3_PAGE1_VLD     0x15FB

// Interrupt Status Register
#define REG_ISR                     0x1600                   
#define         ISR_SMB                         1                 
#define         ISR_TIMER                       2                   // Interrupt when Timer is counted down to zero
#define         ISR_MANUAL                      4                   // Software manual interrupt, for debug. Set when SW_MAN_INT_EN is set in Table 51 Selene Master Control Register (Offset 0x1400).
#define         ISR_HW_RXF_OV                   8                   // RXF overflow interrupt
#define         ISR_HOST_RXF0_OV                0x10
#define         ISR_HOST_RXF1_OV                0x20
#define         ISR_HOST_RXF2_OV                0x40
#define         ISR_HOST_RXF3_OV                0x80
#define         ISR_TXF_UN                      0x100
#define         ISR_RX0_PAGE_FULL               0x200
#define         ISR_DMAR_TO_RST                 0x400
#define         ISR_DMAW_TO_RST                 0x800
#define         ISR_GPHY                        0x1000
#define         ISR_TX_CREDIT                   0x2000
#define         ISR_GPHY_LPW                    0x4000              // GPHY low power state interrupt
#define         ISR_RX_PKT                      0x10000             // One packet received, triggered by RFD
#define         ISR_TX_PKT                      0x20000             // One packet transmitted, triggered by TPD
#define         ISR_TX_DMA                      0x40000
#define         ISR_RX_PKT_1                    0x80000
#define         ISR_RX_PKT_2                    0x100000
#define         ISR_RX_PKT_3                    0x200000
#define         ISR_MAC_RX                      0x400000
#define         ISR_MAC_TX                      0x800000
#define         ISR_UR_DETECTED                 0x1000000
#define         ISR_FERR_DETECTED               0x2000000
#define         ISR_NFERR_DETECTED              0x4000000
#define         ISR_CERR_DETECTED               0x8000000
#define         ISR_PHY_LINKDOWN                0x10000000
#define         ISR_DIS_INT                     0x80000000


// Interrupt Mask Register
#define REG_IMR                     0x1604             


#define IMR_NORMAL_MASK     (\
/*	ISR_SMB			|     */   \
    ISR_TXF_UN      |        \
    ISR_HW_RXF_OV   |        \
    ISR_HOST_RXF0_OV|        \
    ISR_MANUAL      |        \
    ISR_GPHY        |        \
    ISR_GPHY_LPW    |        \
    ISR_DMAR_TO_RST |        \
    ISR_DMAW_TO_RST |        \
    ISR_PHY_LINKDOWN|        \
    ISR_RX_PKT      |        \
    ISR_TX_PKT               )
#define ISR_TX_EVENT    (\
    ISR_TXF_UN      |\
    ISR_TX_PKT)
#define ISR_RX_EVENT    (\
    ISR_HOST_RXF0_OV    |\
    ISR_HW_RXF_OV       |\
    ISR_RX_PKT)
 
    
// Hardware Offset Register
#define REG_HOST_RXF0_PAGEOFF           0x1800
#define REG_TPD_CONS_IDX                0x1804
#define REG_HOST_RXF1_PAGEOFF           0x1808
#define REG_HOST_RXF2_PAGEOFF           0x180C
#define REG_HOST_RXF3_PAGEOFF           0x1810

// RXF-Page 0-3 Offset DMA Address
#define REG_HOST_RXF0_MB0_LO        0x1820
#define REG_HOST_RXF0_MB1_LO        0x1824
#define REG_HOST_RXF1_MB0_LO        0x1828
#define REG_HOST_RXF1_MB1_LO        0x182C
#define REG_HOST_RXF2_MB0_LO        0x1830
#define REG_HOST_RXF2_MB1_LO        0x1834
#define REG_HOST_RXF3_MB0_LO        0x1838
#define REG_HOST_RXF3_MB1_LO        0x183C

// Tpd CMB DMA Address
#define REG_HOST_TX_CMB_LO          0x1840
#define REG_HOST_SMB_ADDR_LO        0x1844



/***************************** MII definition ***************************************/
/* PHY Common Register */
#define MII_BMCR                        0x00       
#define MII_BMSR                        0x01      
#define MII_PHYSID1                     0x02     
#define MII_PHYSID2                     0x03    
#define MII_ADVERTISE                   0x04    
#define MII_LPA                         0x05   
#define MII_EXPANSION                   0x06        
#define MII_AT001_CR                    0x09       
#define MII_AT001_SR                    0x0A        
#define MII_AT001_ESR                   0x0F        
#define MII_AT001_PSCR                  0x10        
#define MII_AT001_PSSR                  0x11       
#define MII_DCOUNTER                    0x12        
#define MII_FCSCOUNTER                  0x13       
#define MII_SMARTSPEED                  0x14   
#define MII_RERRCOUNTER                 0x15        
#define MII_SREVISION                   0x16        
#define MII_RESV1                       0x17        
#define MII_LBRERROR                    0x18       
#define MII_PHYADDR                     0x19        
#define MII_RESV2                       0x1a        
#define MII_TPISTATUS                   0x1b       
#define MII_NCONFIG                     0x1c  

#define MII_DBG_ADDR			0x1D
#define MII_DBG_DATA			0x1E 


/* PHY Control Register */
#define MII_CR_SPEED_SELECT_MSB                  0x0040  /* bits 6,13: 10=1000, 01=100, 00=10 */
#define MII_CR_COLL_TEST_ENABLE                  0x0080  /* Collision test enable */
#define MII_CR_FULL_DUPLEX                       0x0100  /* FDX =1, half duplex =0 */
#define MII_CR_RESTART_AUTO_NEG                  0x0200  /* Restart auto negotiation */
#define MII_CR_ISOLATE                           0x0400  /* Isolate PHY from MII */
#define MII_CR_POWER_DOWN                        0x0800  /* Power down */
#define MII_CR_AUTO_NEG_EN                       0x1000  /* Auto Neg Enable */
#define MII_CR_SPEED_SELECT_LSB                  0x2000  /* bits 6,13: 10=1000, 01=100, 00=10 */
#define MII_CR_LOOPBACK                          0x4000  /* 0 = normal, 1 = loopback */
#define MII_CR_RESET                             0x8000  /* 0 = normal, 1 = PHY reset */
#define MII_CR_SPEED_MASK                        0x2040
#define MII_CR_SPEED_1000                        0x0040
#define MII_CR_SPEED_100                         0x2000
#define MII_CR_SPEED_10                          0x0000


/* PHY Status Register */
#define MII_SR_EXTENDED_CAPS                     0x0001  /* Extended register capabilities */
#define MII_SR_JABBER_DETECT                     0x0002  /* Jabber Detected */
#define MII_SR_LINK_STATUS                       0x0004  /* Link Status 1 = link */
#define MII_SR_AUTONEG_CAPS                      0x0008  /* Auto Neg Capable */
#define MII_SR_REMOTE_FAULT                      0x0010  /* Remote Fault Detect */
#define MII_SR_AUTONEG_COMPLETE                  0x0020  /* Auto Neg Complete */
#define MII_SR_PREAMBLE_SUPPRESS                 0x0040  /* Preamble may be suppressed */
#define MII_SR_EXTENDED_STATUS                   0x0100  /* Ext. status info in Reg 0x0F */
#define MII_SR_100T2_HD_CAPS                     0x0200  /* 100T2 Half Duplex Capable */
#define MII_SR_100T2_FD_CAPS                     0x0400  /* 100T2 Full Duplex Capable */
#define MII_SR_10T_HD_CAPS                       0x0800  /* 10T   Half Duplex Capable */
#define MII_SR_10T_FD_CAPS                       0x1000  /* 10T   Full Duplex Capable */
#define MII_SR_100X_HD_CAPS                      0x2000  /* 100X  Half Duplex Capable */
#define MII_SR_100X_FD_CAPS                      0x4000  /* 100X  Full Duplex Capable */
#define MII_SR_100T4_CAPS                        0x8000  /* 100T4 Capable */

/* Link partner ability register. */
#define MII_LPA_SLCT                             0x001f  /* Same as advertise selector  */
#define MII_LPA_10HALF                           0x0020  /* Can do 10mbps half-duplex   */
#define MII_LPA_10FULL                           0x0040  /* Can do 10mbps full-duplex   */
#define MII_LPA_100HALF                          0x0080  /* Can do 100mbps half-duplex  */
#define MII_LPA_100FULL                          0x0100  /* Can do 100mbps full-duplex  */
#define MII_LPA_100BASE4                         0x0200  /* 100BASE-T4  */
#define MII_LPA_PAUSE                            0x0400  /* PAUSE */
#define MII_LPA_ASYPAUSE                         0x0800  /* Asymmetrical PAUSE */
#define MII_LPA_RFAULT                           0x2000  /* Link partner faulted        */
#define MII_LPA_LPACK                            0x4000  /* Link partner acked us       */
#define MII_LPA_NPAGE                            0x8000  /* Next page bit               */

/* Autoneg Advertisement Register */
#define MII_AR_SELECTOR_FIELD                   0x0001  /* indicates IEEE 802.3 CSMA/CD */
#define MII_AR_10T_HD_CAPS                      0x0020  /* 10T   Half Duplex Capable */
#define MII_AR_10T_FD_CAPS                      0x0040  /* 10T   Full Duplex Capable */
#define MII_AR_100TX_HD_CAPS                    0x0080  /* 100TX Half Duplex Capable */
#define MII_AR_100TX_FD_CAPS                    0x0100  /* 100TX Full Duplex Capable */
#define MII_AR_100T4_CAPS                       0x0200  /* 100T4 Capable */
#define MII_AR_PAUSE                            0x0400  /* Pause operation desired */
#define MII_AR_ASM_DIR                          0x0800  /* Asymmetric Pause Direction bit */
#define MII_AR_REMOTE_FAULT                     0x2000  /* Remote Fault detected */
#define MII_AR_NEXT_PAGE                        0x8000  /* Next Page ability supported */
#define MII_AR_SPEED_MASK                       0x01E0
#define MII_AR_DEFAULT_CAP_MASK                 0x0DE0

/* 1000BASE-T Control Register */
#define MII_AT001_CR_1000T_HD_CAPS              0x0100  /* Advertise 1000T HD capability */
#define MII_AT001_CR_1000T_FD_CAPS              0x0200  /* Advertise 1000T FD capability  */
#define MII_AT001_CR_1000T_REPEATER_DTE         0x0400  /* 1=Repeater/switch device port */
                                                        /* 0=DTE device */
#define MII_AT001_CR_1000T_MS_VALUE             0x0800  /* 1=Configure PHY as Master */
                                                        /* 0=Configure PHY as Slave */
#define MII_AT001_CR_1000T_MS_ENABLE            0x1000  /* 1=Master/Slave manual config value */
                                                        /* 0=Automatic Master/Slave config */
#define MII_AT001_CR_1000T_TEST_MODE_NORMAL     0x0000  /* Normal Operation */
#define MII_AT001_CR_1000T_TEST_MODE_1          0x2000  /* Transmit Waveform test */
#define MII_AT001_CR_1000T_TEST_MODE_2          0x4000  /* Master Transmit Jitter test */
#define MII_AT001_CR_1000T_TEST_MODE_3          0x6000  /* Slave Transmit Jitter test */
#define MII_AT001_CR_1000T_TEST_MODE_4          0x8000  /* Transmitter Distortion test */
#define MII_AT001_CR_1000T_SPEED_MASK           0x0300
#define MII_AT001_CR_1000T_DEFAULT_CAP_MASK     0x0300

/* 1000BASE-T Status Register */
#define MII_AT001_SR_1000T_LP_HD_CAPS           0x0400  /* LP is 1000T HD capable */
#define MII_AT001_SR_1000T_LP_FD_CAPS           0x0800  /* LP is 1000T FD capable */
#define MII_AT001_SR_1000T_REMOTE_RX_STATUS     0x1000  /* Remote receiver OK */
#define MII_AT001_SR_1000T_LOCAL_RX_STATUS      0x2000  /* Local receiver OK */
#define MII_AT001_SR_1000T_MS_CONFIG_RES        0x4000  /* 1=Local TX is Master, 0=Slave */
#define MII_AT001_SR_1000T_MS_CONFIG_FAULT      0x8000  /* Master/Slave config fault */
#define MII_AT001_SR_1000T_REMOTE_RX_STATUS_SHIFT   12
#define MII_AT001_SR_1000T_LOCAL_RX_STATUS_SHIFT    13

/* Extended Status Register */
#define MII_AT001_ESR_1000T_HD_CAPS             0x1000  /* 1000T HD capable */
#define MII_AT001_ESR_1000T_FD_CAPS             0x2000  /* 1000T FD capable */
#define MII_AT001_ESR_1000X_HD_CAPS             0x4000  /* 1000X HD capable */
#define MII_AT001_ESR_1000X_FD_CAPS             0x8000  /* 1000X FD capable */

/* AT001 PHY Specific Control Register */
#define MII_AT001_PSCR_JABBER_DISABLE           0x0001  /* 1=Jabber Function disabled */
#define MII_AT001_PSCR_POLARITY_REVERSAL        0x0002  /* 1=Polarity Reversal enabled */
#define MII_AT001_PSCR_SQE_TEST                 0x0004  /* 1=SQE Test enabled *//
#define MII_AT001_PSCR_MAC_POWERDOWN            0x0008 
#define MII_AT001_PSCR_CLK125_DISABLE           0x0010  /* 1=CLK125 low,
                                                         * 0=CLK125 toggling
                                                         */
#define MII_AT001_PSCR_MDI_MANUAL_MODE          0x0000  /* MDI Crossover Mode bits 6:5 */
                                                        /* Manual MDI configuration */
#define MII_AT001_PSCR_MDIX_MANUAL_MODE         0x0020  /* Manual MDIX configuration */
#define MII_AT001_PSCR_AUTO_X_1000T             0x0040  /* 1000BASE-T: Auto crossover,
                                                         *  100BASE-TX/10BASE-T:
                                                         *  MDI Mode
                                                         */
#define MII_AT001_PSCR_AUTO_X_MODE              0x0060  /* Auto crossover enabled
                                                         * all speeds.
                                                         */
#define MII_AT001_PSCR_10BT_EXT_DIST_ENABLE     0x0080
                                                        /* 1=Enable Extended 10BASE-T distance
                                                         * (Lower 10BASE-T RX Threshold)
                                                         * 0=Normal 10BASE-T RX Threshold */
#define MII_AT001_PSCR_MII_5BIT_ENABLE          0x0100
                                                        /* 1=5-Bit interface in 100BASE-TX
                                                         * 0=MII interface in 100BASE-TX */
#define MII_AT001_PSCR_SCRAMBLER_DISABLE        0x0200  /* 1=Scrambler disable */
#define MII_AT001_PSCR_FORCE_LINK_GOOD          0x0400  /* 1=Force link good */
#define MII_AT001_PSCR_ASSERT_CRS_ON_TX         0x0800  /* 1=Assert CRS on Transmit */
#define MII_AT001_PSCR_POLARITY_REVERSAL_SHIFT    1
#define MII_AT001_PSCR_AUTO_X_MODE_SHIFT          5
#define MII_AT001_PSCR_10BT_EXT_DIST_ENABLE_SHIFT 7


/* AT001 PHY Specific Status Register */
#define MII_AT001_PSSR_SPD_DPLX_RESOLVED        0x0800  /* 1=Speed & Duplex resolved */
#define MII_AT001_PSSR_DPLX                     0x2000  /* 1=Duplex 0=Half Duplex */
#define MII_AT001_PSSR_SPEED                    0xC000  /* Speed, bits 14:15 */
#define MII_AT001_PSSR_10MBS                    0x0000  /* 00=10Mbs */
#define MII_AT001_PSSR_100MBS                   0x4000  /* 01=100Mbs */
#define MII_AT001_PSSR_1000MBS                  0x8000  /* 10=1000Mbs */

/*********************PCI Command Register ******************************/
// PCI Command Register Bit Definitions
#define PCI_REG_COMMAND         0x04    // PCI Command Register
#define CMD_IO_SPACE            0x0001
#define CMD_MEMORY_SPACE        0x0002
#define CMD_BUS_MASTER          0x0004

/* Wake Up Filter Control */
#define AT_WUFC_LNKC 0x00000001 /* Link Status Change Wakeup Enable */
#define AT_WUFC_MAG  0x00000002 /* Magic Packet Wakeup Enable */
#define AT_WUFC_EX   0x00000004 /* Directed Exact Wakeup Enable */
#define AT_WUFC_MC   0x00000008 /* Multicast Wakeup Enable */
#define AT_WUFC_BC   0x00000010 /* Broadcast Wakeup Enable */

/************************************************************************************************************************/
    
/* Error Codes */

#define AT_SUCCESS                      0
#define AT_ERR_EEPROM                   1
#define AT_ERR_PHY                      2
#define AT_ERR_CONFIG                   3
#define AT_ERR_PARAM                    4
#define AT_ERR_MAC_TYPE                 5
#define AT_ERR_PHY_TYPE                 6
#define AT_ERR_PHY_SPEED                7
#define AT_ERR_PHY_RES                  8


/* The size (in bytes) of a ethernet packet */
#define ENET_HEADER_SIZE                14
#define MAXIMUM_ETHERNET_FRAME_SIZE     1518 /* with FCS */
#define MINIMUM_ETHERNET_FRAME_SIZE     64   /* with FCS */
#define ETHERNET_FCS_SIZE               4
#define MAX_JUMBO_FRAME_SIZE            0x2000
#define VLAN_SIZE                                               4

#define PHY_AUTO_NEG_TIME               45          /* 4.5 Seconds */
#define PHY_FORCE_TIME                  20          /* 2.0 Seconds */

/* For checksumming , the sum of all words in the EEPROM should equal 0xBABA */
#define EEPROM_SUM                      0xBABA
#define NODE_ADDRESS_SIZE               6


/* TPD definition */
typedef struct _TpdDescr {
	u64         addr;
	u16         buf_len :14;
	u16         dma_int :1;
	u16         tx_int  :1;
	u16         vlan;
	u16         eop     :1;
	u16         ipver   :1;     // 0 : IPV4, 1:IPV6
	u16         ins_vlan:1;
	u16         my_xsum :1;
	u16         segment :1;
	u16         ipxsum  :1;
	u16         tcpxsum :1;
	u16         udpxsum :1;
	u16         vlan_tag:1;
	u16         eth_type:1;
	u16         iphdrlen:4;
	u16         tcphdrlen:4;
	u16         hdr_flag:1;
	u16         tcp_mss :13;
} _AT_ATTRIB_PACK_ TpdDescr;

typedef struct _TpdIPv6Descr {
	u64         addr;
	u16         buf_len :14;
	u16         dma_int :1;
	u16         tx_int  :1;
	u16         vlan;
	u16         eop     :1;
	u16         ipver   :1;     // 0 : IPV4, 1:IPV6
	u16         ins_vlan:1;
	u16         my_xsum :1;
	u16         segment :1;
	u16         ipv6hdrlen_1:3;
	u16         vlan_tag:1;
	u16         eth_type:1;
	u16         ipv6hdrlen_2:4;
	u16         tcphdrlen:4;
	u16         hdr_flag:1;
	u16         tcp_mss :13;
} _AT_ATTRIB_PACK_ TpdIPv6Descr;

// Tpd for custom checksum 
typedef struct _TpdCXsumDescr {
	u64        addr;
	u16        buf_len :14;
	u16        dma_int :1;
	u16        tx_int  :1;
	u16        vlan;
	u16        eop     :1;
	u16        coals   :1;
	u16        ins_vlan:1;
        u16        my_xsum :1;
	u16        segment :1;
	u16        ipxsum  :1;
	u16        tcpxsum :1;
	u16        udpxsum :1;
	u16        vlan_tag:1;
	u16        eth_type:1;
	u16        iphdrlen:4;
	u16        tcphdrlen:2;
	u16        payld_ofs:8;
	u16        psdxsum_ofs:8;
} _AT_ATTRIB_PACK_ TpdCXsumDescr;
#define MAX_TX_BUF_LEN  0x3000

/* RRS(Receive Return Status) definition */
typedef struct _RecvRetStatus {
	u16        seq_num         ;
	u16        hash_lo         ;
	u16        ippld_xsum      ; /* ip payload checksum */
	u16        pkt_len :14     ;
	u16        cpu_n   :2      ;
	// packet flags
	u16        rss_ipv4:1	   ;
	u16        rss_ipv4_tcp:1  ;
	u16        rss_ipv6:1      ;
	u16        rss_ipv6_tcp:1  ;
	u16        ipv6	:1         ;
	u16        ipv4_mf:1       ;
	u16        ipv4_df:1       ;
		
	u16        eth_type:1      ;
	u16        vlan    :1      ;
	u16        err     :1      ;
	u16        ipv4    :1      ;
	u16        udp     :1      ;
	u16        tcp     :1      ;
	u16        bcast   :1      ;
	u16        mcast   :1      ;
	u16        pause   :1      ;
	// error info
	u16        crc     :1      ;
	u16        code    :1      ;
	u16        dribble :1      ;
	u16        runt    :1      ;
	u16        ov      :1      ;
	u16        trunc   :1      ;
	u16        ip_xsum :1      ;
	u16        l4_xsum :1      ;
	u16        length  :1      ;
	u16        dest    :1      ;
	u16        res2    :6      ;
		
	u16        hash_hi ;
	u16        vtag    ; // vlan tag if bit vlan == 1
} _AT_ATTRIB_PACK_ RecvRetStatus;

typedef struct _RxFlags {
	
	// packet flags
	u16        rss_ipv4:1	   ;
	u16        rss_ipv4_tcp:1  ;
	u16        rss_ipv6:1      ;
	u16        rss_ipv6_tcp:1  ;
	u16        ipv6	:1         ;
	u16        ipv4_mf:1       ;
	u16        ipv4_df:1       ;
		
	u16        eth_type:1      ;
	u16        vlan    :1      ;
	u16        err     :1      ;
	u16        ipv4    :1      ;
	u16        udp     :1      ;
	u16        tcp     :1      ;
	u16        bcast   :1      ;
	u16        mcast   :1      ;
	u16        pause   :1      ;
	// error info
	u16        crc     :1      ;
	u16        code    :1      ;
	u16        dribble :1      ;
	u16        runt    :1      ;
	u16        ov      :1      ;
	u16        trunc   :1      ;
	u16        ip_xsum :1      ;
	u16        l4_xsum :1      ;
	u16        length  :1      ;
	u16        dest    :1      ;
	u16        res2    :6      ;

} _AT_ATTRIB_PACK_ RxFlags;                      

typedef enum {
    atl1e_10_half = 0,
    atl1e_10_full = 1,
    atl1e_100_half = 2,
    atl1e_100_full = 3
} atl1e_speed_duplex_type;

typedef enum  {
	atl1e_dma_req_128 = 0,
	atl1e_dma_req_256 = 1,
	atl1e_dma_req_512 = 2,
	atl1e_dma_req_1024 = 3,
	atl1e_dma_req_2048 = 4,
	atl1e_dma_req_4096 = 5
}atl1e_dma_req_block ;

typedef enum {
	atl1e_rrs_disable = 0,
	atl1e_rrs_ipv4 = 1,
	atl1e_rrs_ipv4_tcp = 2,
	atl1e_rrs_ipv6 = 4,
	atl1e_rss_ipv6_tcp = 8
} atl1e_rrs_type;

typedef enum {
	athr_l1e 	  = 0,
	athr_l2e_revA = 1,
	athr_l2e_revB = 2,
    athr_l1c_revA = 3,
    athr_l2c_revA = 4,
} atl1e_nic_type;
	
struct atl1e_hw_operations {
    int (*power_ctrl_init) (struct atl1e_hw *);
    int (*power_ctrl_link_chg) (struct atl1e_hw *);
    int (*power_ctrl_suspend_init) (struct atl1e_hw *);
    int (*power_ctrl_suspend_exit) (struct atl1e_hw *);
    int (*phy_ctrl_link_chg) (struct atl1e_hw *);
    int (*blink_led) (struct atl1e_hw *);
};

/* Structure containing variables used by the shared code (atl1e_hw.c) */
struct atl1e_hw {
    u8 *hw_addr;
    void *back;

    struct atl1e_hw_operations ops;
    atl1e_nic_type  nic_type;
	atl1e_rrs_type rrs_type;
	atl1e_dma_req_block dmar_block;
	atl1e_dma_req_block dmaw_block;
	
    u8 preamble_len;
    u16 rx_jumbo_th;
    u16 max_frame_size;	
    u16 media_type;
    u16 autoneg_advertised;
    u16 pci_cmd_word;

    u16 mii_autoneg_adv_reg;
    u16 mii_1000t_ctrl_reg;
    
    u32 smb_timer;
    u32 base_cpu;
    u32 indirect_tab;
    u32 mem_rang;
    
    u16 device_id;
    u16 vendor_id;
    u16 subsystem_id; 
    u16 subsystem_vendor_id;
    u8  revision_id; 

    u8 mac_addr[NODE_ADDRESS_SIZE];
    u8 perm_mac_addr[NODE_ADDRESS_SIZE];
    u32 link_cap_flags;
#define LINK_CAP_SPEED_1000 0x0001
    u32 power_ctrl_flags;
#define POWER_ASPM_L0S_EN   0x0001
#define POWER_ASPM_L1_EN    0x0002
    u8 pm_l0s_timer;
    u8 pm_l1_timer;
    boolean_t phy_configured;
    boolean_t re_autoneg;
    boolean_t emi_ca;   
    
};

#endif//_ATL1E_HW_H_
