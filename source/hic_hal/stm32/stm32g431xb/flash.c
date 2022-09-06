/**
 * @file    flash_hal_stm32f103xb.c
 * @brief
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2019, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "flash_hal.h"        // FlashOS Structures
#include "target_config.h"    // target_device
#include "stm32g4xx.h"
#include "util.h"
#include "target_board.h"

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
uint32_t Init(uint32_t adr, uint32_t clk, uint32_t fnc)
{
    //
    // No special init required
    //
    return (0);
}

uint32_t UnInit(uint32_t fnc)
{
    //
    // No special uninit required
    //
    return (0);
}

uint32_t EraseChip(void)
{
    #if 0
    FLASH_EraseInitTypeDef erase_init = {0};
    uint32_t error;
    uint32_t ret = 0;

    if (g_board_info.target_cfg) {
        HAL_FLASH_Unlock();

        //bootloader, interface flashing only concerns 1 flash region
        util_assert((g_board_info.target_cfg->flash_regions[0].end - g_board_info.target_cfg->flash_regions[0].start) % FLASH_PAGE_SIZE == 0);

        erase_init.TypeErase = FLASH_TYPEERASE_PAGES;
        erase_init.Page = g_board_info.target_cfg->flash_regions[0].start;
        erase_init.NbPages = (g_board_info.target_cfg->flash_regions[0].end - g_board_info.target_cfg->flash_regions[0].start) % FLASH_PAGE_SIZE;

        if (HAL_FLASHEx_Erase(&erase_init, &error) != HAL_OK) {
            ret = 1;
        }

        HAL_FLASH_Lock();
    } else {
        ret = 1;
    }

    return ret;
    #endif
    return 1;
}

uint32_t EraseSector(uint32_t adr)
{
    #if 0
    FLASH_EraseInitTypeDef erase_init = {0};
    uint32_t error;
    uint32_t ret = 0;

    HAL_FLASH_Unlock();

    erase_init.TypeErase = FLASH_TYPEERASE_PAGES;
    erase_init.Page = adr;
    erase_init.NbPages = 1;

    if (HAL_FLASHEx_Erase(&erase_init, &error) != HAL_OK) {
        ret = 1;
    }

    HAL_FLASH_Lock();

    return ret;
    #endif
    return 1;
}

uint32_t ProgramPage(uint32_t adr, uint32_t sz, uint32_t *buf)
{
    #if 0
    uint32_t i;
    uint32_t ret = 0;

    HAL_FLASH_Unlock();

    util_assert(sz % 8 == 0);

    for (i = 0; i < sz / 8; i++) {
        uint64_t data = buf[2*i] | buf[2*i+1];

        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, adr + i * 8, data) != HAL_OK) {
            ret = 1;
            break;
        }
    }

    HAL_FLASH_Lock();

    return ret;
    #endif
    return 1;
}
