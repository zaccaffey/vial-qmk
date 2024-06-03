#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_armada( \
  r06cn1, r06c00, r06c01, r06c02, r06c03, r06c04, r06c05, r06c06, r06c07,           r06c09, r06c10, r06c11, r06c12, r06c13, r06c14, r06c15, r06c16,           r06c17, r06c18, r06c19, r06c20, r06c21, r06c22, r06c23, \
  r05cn1, r05c00, r05c01, r05c02, r05c03, r05c04, r05c05, r05c06, r05c07, r05c08,   r05c09, r05c10, r05c11, r05c12, r05c13, r05c14, r05c15, r05c16,           r05c17, r05c18, r05c19, r05c20, r05c21, r05c22, r05c23, \
  r04cn1, r04c00, r04c01, r04c02, r04c03, r04c04, r04c05, r04c06, r04c07,           r03c09, r04c09, r04c10, r04c11, r04c12, r04c13, r04c14, r04c15, r04c16,   r04c17, r04c18, r04c19, r04c20, r04c21, r04c22, r04c23, \
  r03cn1, r03c00, r03c01,         r03c03, r03c04, r03c05, r03c06, r03c07, r03c08,   r02c09, r03c10, r03c11, r03c12, r03c13, r03c14, r03c15, r03c16,                                   r03c20, r03c21, r03c22, \
  r02cn1, r02c00,         r02c02, r02c03, r02c04, r02c05, r02c06, r02c07, r02c08,   r02c10, r02c11, r02c12, r02c13, r02c14, r02c15, r02c16,                           r02c18,         r02c20, r02c21, r02c22, r02c23, \
  r01cn1, r01c00, r01c01, r01c02,         r01c04,                 r01c07,           r01c11, r01c13, r01c14, r01c15, r01c16,                                   r01c17, r01c18, r01c19, r01c20,         r01c22 \
) \
{ \
    { r01cn1, r01c00, r01c01, r01c02, KC_NO,  r01c04, KC_NO,  KC_NO,  r01c07, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO  }, \
    { r02cn1, r02c00, KC_NO,  r02c02, r02c03, r02c04, r02c05, r02c06, r02c07, r02c08, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO  }, \
    { r03cn1, r03c00, r03c01, KC_NO,  r03c03, r03c04, r03c05, r03c06, r03c07, r03c08, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO  }, \
    { r04cn1, r04c00, r04c01, r04c02, r04c03, r04c04, r04c05, r04c06, r04c07, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO  }, \
    { r05cn1, r05c00, r05c01, r05c02, r05c03, r05c04, r05c05, r05c06, r05c07, r05c08, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO  }, \
    { r06cn1, r06c00, r06c01, r06c02, r06c03, r06c04, r06c05, r06c06, r06c07, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO  }, \
\
    { KC_NO,  KC_NO,  r01c11, KC_NO,  r01c13, r01c14, r01c15, r01c16,   r01c17, r01c18, r01c19, r01c20, KC_NO,  r01c22, KC_NO  }, \
    { r02c09, r02c10, r02c11, r02c12, r02c13, r02c14, r02c15, r02c16,   KC_NO,  r02c18, KC_NO,  r02c20, r02c21, r02c22, r02c23 }, \
    { r03c09, r03c10, r03c11, r03c12, r03c13, r03c14, r03c15, r03c16,   KC_NO,  KC_NO,  KC_NO,  r03c20, r03c21, r03c22, KC_NO  }, \
    { r04c09, r04c10, r04c11, r04c12, r04c13, r04c14, r04c15, r04c16,   r04c17, r04c18, r04c19, r04c20, r04c21, r04c22, r04c23 }, \
    { r05c09, r05c10, r05c11, r05c12, r05c13, r05c14, r05c15, r05c16,   r05c17, r05c18, r05c19, r05c20, r05c21, r05c22, r05c23 }, \
    { r06c09, r06c10, r06c11, r06c12, r06c13, r06c14, r06c15, r06c16,   r06c17, r06c18, r06c19, r06c20, r06c21, r06c22, r06c23 } \
}
