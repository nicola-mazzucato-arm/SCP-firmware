/*
 * Arm SCP/MCP Software
 * Copyright (c) 2018-2020, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "n1sdp_scp_system_mmap.h"

#include <mod_fip.h>
#include <mod_n1sdp_rom.h>

#include <fwk_module.h>

const struct fwk_module_config config_n1sdp_rom = {
    .data = &((struct n1sdp_rom_config){
        .ramfw_base = SCP_RAM0_BASE,
        .image_type = MOD_FIP_TOC_ENTRY_SCP_BL2,
    })
};
