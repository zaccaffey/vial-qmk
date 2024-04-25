/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#ifdef POINTING_DEVICE_ENABLE
#    ifndef NO_CHARYBDIS_KEYCODES
enum charybdis_keycodes {
    LEFT_POINTER_DEFAULT_DPI_FORWARD = QK_KB_0,
    LEFT_POINTER_DEFAULT_DPI_REVERSE,
    LEFT_POINTER_SNIPING_DPI_FORWARD,
    LEFT_POINTER_SNIPING_DPI_REVERSE,
    LEFT_SNIPING_MODE,
    LEFT_SNIPING_MODE_TOGGLE,
    LEFT_DRAGSCROLL_MODE,
    LEFT_DRAGSCROLL_MODE_TOGGLE,POINTER_DEFAULT_DPI_FORWARD,
    RIGHT_POINTER_DEFAULT_DPI_REVERSE,
    RIGHT_POINTER_SNIPING_DPI_FORWARD,
    RIGHT_POINTER_SNIPING_DPI_REVERSE,
    RIGHT_SNIPING_MODE,
    RIGHT_SNIPING_MODE_TOGGLE,
    RIGHT_DRAGSCROLL_MODE,
    RIGHT_DRAGSCROLL_MODE_TOGGLE,
};

#        define L_DPI_MOD POINTER_DEFAULT_DPI_FORWARD
#        define L_DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#        define L_S_D_MOD POINTER_SNIPING_DPI_FORWARD
#        define L_S_D_RMOD POINTER_SNIPING_DPI_REVERSE
#        define L_SNIPING SNIPING_MODE
#        define L_SNP_TOG SNIPING_MODE_TOGGLE
#        define L_DRGSCRL DRAGSCROLL_MODE
#        define L_DRG_TOG DRAGSCROLL_MODE_TOGGLE
#        define R_DPI_MOD POINTER_DEFAULT_DPI_FORWARD
#        define R_DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#        define R_S_D_MOD POINTER_SNIPING_DPI_FORWARD
#        define R_S_D_RMOD POINTER_SNIPING_DPI_REVERSE
#        define R_SNIPING SNIPING_MODE
#        define R_SNP_TOG SNIPING_MODE_TOGGLE
#        define R_DRGSCRL DRAGSCROLL_MODE
#        define R_DRG_TOG DRAGSCROLL_MODE_TOGGLE
#    endif // !NO_CHARYBDIS_KEYCODES

/** \brief Return the current DPI value for the pointer's default mode. */
uint16_t charybdis_get_pointer_default_dpi(bool is_left);

/**
 * \brief Update the pointer's default DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to CHARYBDIS_DEFAULT_DPI_CONFIG_STEP.
 *
 * The new value is persisted in EEPROM.
 */
void charybdis_cycle_pointer_default_dpi(bool forward, bool is_left);

/**
 * \brief Same as `charybdis_cycle_pointer_default_dpi`, but do not write to
 * EEPROM.
 *
 * This means that reseting the board will revert the value to the last
 * persisted one.
 */
void charybdis_cycle_pointer_default_dpi_noeeprom(bool forward, bool is_left);

/** \brief Return the current DPI value for the pointer's sniper-mode. */
uint16_t charybdis_get_pointer_sniping_dpi(bool is_left);

/**
 * \brief Update the pointer's sniper-mode DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to CHARYBDIS_SNIPING_DPI_CONFIG_STEP.
 *
 * The new value is persisted in EEPROM.
 */
void charybdis_cycle_pointer_sniping_dpi(bool forward, bool is_left);

/**
 * \brief Same as `charybdis_cycle_pointer_sniping_dpi`, but do not write to
 * EEPROM.
 *
 * This means that reseting the board will revert the value to the last
 * persisted one.
 */
void charybdis_cycle_pointer_sniping_dpi_noeeprom(bool forward, bool is_left);

/** \brief Whether sniper-mode is enabled. */
bool charybdis_get_pointer_sniping_enabled(bool is_left);

/**
 * \brief Enable/disable sniper mode.
 *
 * When sniper mode is enabled the dpi is reduced to slow down the pointer for
 * more accurate movements.
 */
void charybdis_set_pointer_sniping_enabled(bool enable, bool is_left);

/** \brief Whether drag-scroll is enabled. */
bool charybdis_get_pointer_dragscroll_enabled(bool is_left);

/**
 * \brief Enable/disable drag-scroll mode.
 *
 * When drag-scroll mode is enabled, horizontal and vertical pointer movements
 * are translated into horizontal and vertical scroll movements.
 */
void charybdis_set_pointer_dragscroll_enabled(bool enable, bool is_left);
#endif // POINTING_DEVICE_ENABLE
