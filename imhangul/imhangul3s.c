/* GTK - The GIMP Toolkit
 * Copyright (C) 2002 Choe Hwanjin
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: Choe Hwanjin <krisna@kldp.org>
 * this module is for hangul 3bul sik mode users
 */

#include <string.h>

#include <gdk/gdkkeysyms.h>

/*
#include "gtk/gtkintl.h"
#include "gtk/gtkimmodule.h"
*/
#include <gtk/gtkimmodule.h>

#include "imhangul.h"

static const GtkIMContextInfo hangul3s_info = {
  "hangul3s",
  "Hangul 3bul No-Shift",
  "gtk+",
  GTK_LOCALEDIR,
  ""
};

static const GtkIMContextInfo *info_list[] = {
  &hangul3s_info
};

#include "imhangul3.h"

/* hangul keyboard type: sebulsik no-shift(sun a rae) */
/* return ucs4 code jamo choseong value(U+1100 ~ U+1112) in 3bul keyboard
 * if it is not hangul key, return 0 */
static gunichar
im_hangul3_choseong_sun(guint keyval, guint state) {
  if (is_set(state, GDK_SHIFT_MASK))
    return 0;
  switch (keyval) {
    case GDK_K:
    case GDK_k:
      return 0x1100;	/* choseong kiyeok */
    case GDK_H:		                           
    case GDK_h:		                           
      return 0x1102;    /* choseong nieun */
    case GDK_U:		                           
    case GDK_u:		                           
      return 0x1103;    /* choseong tikeut */
    case GDK_Y:		                           
    case GDK_y:		                           
      return 0x1105;    /* choseong rieul */
    case GDK_I:		                           
    case GDK_i:		                           
      return 0x1106;    /* choseong mieum */
    case GDK_semicolon:	                           
      return 0x1107;    /* choseong pieup */
    case GDK_N:		                           
    case GDK_n:		                           
      return 0x1109;    /* choseong sios */
    case GDK_J:		                           
    case GDK_j:		                           
      return 0x110b;    /* choseong ieung */
    case GDK_L:		                           
    case GDK_l:		                           
      return 0x110c;    /* choseong cieuc */
    case GDK_O:		                           
    case GDK_o:		                           
      return 0x110e;    /* choseong chieuch */
    case GDK_9:		                           
      return 0x110f;    /* choseong khieukh */
    case GDK_apostrophe:                           
      return 0x1110;    /* choseong thieuth */
    case GDK_P:		                           
    case GDK_p:		                           
      return 0x1111;    /* choseong phieuph */
    case GDK_M:		                           
    case GDK_m:		                           
      return 0x1112;    /* choseong hieuh */
  }
  return 0;
}

/* return unicode jamo choseong value(U+1100 ~ U+1112) in 3bul keyboard
 * if it is not hangul key, return 0 */
static gunichar
im_hangul3_comp_choseong_sun(gunichar ch, guint keyval, guint state) {
  if (is_set(state, GDK_SHIFT_MASK))
    return 0;
  switch (ch) {
    case 0x1100:		/* choseong kiyeok */
      switch (keyval) {
	case GDK_K:
	case GDK_k:
          return 0x1101;	/* choseong ssangkiyeok */
      }
      break;
    case 0x1103:		/* choseong tikeut */
      switch (keyval) {
	case GDK_U:
	case GDK_u:
          return 0x1104;	/* choseong ssangtikeut */
      }
      break;
    case 0x1107:		/* choseong pieup */
      switch (keyval) {
	case GDK_semicolon:
          return 0x1108;	/* choseong ssangpieup */
      }
      break;
    case 0x1109:		/* choseong sios */
      switch (keyval) {
	case GDK_N:
	case GDK_n:
          return 0x110a;	/* choseong ssangsios */
      }
      break;
    case 0x110c:		/* choseong cieuc */
      switch (keyval) {
	case GDK_L:
	case GDK_l:
          return 0x110d;	/* choseong ssangcieuc */
      }
      break;
  }
  return 0;
}


/* return unicode jamo jungseong value(U+1161 ~ U+1173) in 3bul keyboard
 * if it is not hangul key, return 0 */
static gunichar
im_hangul3_jungseong_sun(guint keyval, guint state) {
  if (is_set(state, GDK_SHIFT_MASK))
    return 0;
  switch (keyval) {
    case GDK_F:
    case GDK_f:
      return 0x1161;		/* jungseong a */
    case GDK_R:		                      
    case GDK_r:		                      
      return 0x1162;		/* jungseong ae */
    case GDK_6:		                      
      return 0x1163;		/* jungseong ya */
    case GDK_T:		                      
    case GDK_t:		                      
      return 0x1165;		/* jungseong eo */
    case GDK_C:		                      
    case GDK_c:		                      
      return 0x1166;		/* jungseong e */
    case GDK_E:		                      
    case GDK_e:		                      
      return 0x1167;		/* jungseong yeo */
    case GDK_7:		                      
      return 0x1168;		/* jungseong ye */
    case GDK_V:		                      
    case GDK_v:		                      
      return 0x1169;		/* jungseong o */
    case GDK_4:		                      
      return 0x116d;		/* jungseong yo */
    case GDK_B:		                      
    case GDK_b:		                      
      return 0x116e;		/* jungseong u */
    case GDK_5:		                      
      return 0x1172;		/* jungseong yu */
    case GDK_G:		                      
    case GDK_g:		                      
      return 0x1173;		/* jungseong eu */
    case GDK_8:		                      
      return 0x1174;		/* jungseong yi */
    case GDK_D:		                      
    case GDK_d:		                      
      return 0x1175;		/* jungseong i */    
  }
  return 0;
}

/* return unicode jamo jungseong value(U+1161 ~ U+1173) in 3bul keyboard
 * if it is not hangul key, return 0 */
static gunichar
im_hangul3_comp_jungseong_sun(gunichar ch, guint keyval, guint state) {
  if (is_set(state, GDK_SHIFT_MASK))
    return 0;
  switch (ch) {
    case 0x1169:		/* jungseong o */
      switch (keyval) {
        case GDK_F:	
        case GDK_f:	
          return 0x116a;	/* jungseong wa */
        case GDK_R:	        
        case GDK_r:	        
          return 0x116b;        /* jungseong wae */
        case GDK_D:	        
        case GDK_d:	        
          return 0x116c;        /* jungseong oe */
      }
      break;
    case 0x116e:		/* jungseong u */
      switch (keyval) {
        case GDK_T:	
        case GDK_t:	
          return 0x116f;	/* jungseong weo */
        case GDK_C:	        
        case GDK_c:	        
          return 0x1170;        /* jungseong we */
        case GDK_D:	        
        case GDK_d:	        
          return 0x1171;        /* jungseong wi */  
      }
      break;
    case 0x1173:		/* jungseong eu */
      switch (keyval) {
        case GDK_D:
        case GDK_d:
          return 0x1174;	/* jungseong yi */
      }
  }
  return 0;
}

/* return unicode jamo jongseong value(U+11a8 ~ U+11c2) in 3bul keyboard
 * if it is not hangul key, return 0 */
static gunichar
im_hangul3_jongseong_sun(guint keyval, guint state)
{
  if (is_set(state, GDK_SHIFT_MASK))
    return 0;
  switch (keyval) {
    case GDK_X:
    case GDK_x:
      return 0x11a8;    /* jongseong kiyeok */
    case GDK_S:
    case GDK_s:
      return 0x11ab;    /* jongseong nieun */
    case GDK_slash:
      return 0x11ae;    /* jongseong tikeut */
    case GDK_W:
    case GDK_w:
      return 0x11af;    /* jongseong rieul */
    case GDK_Z:
    case GDK_z:
      return 0x11b7;    /* jongseong mieum */
    case GDK_3:
      return 0x11b8;    /* jongseong pieup */
    case GDK_Q:
    case GDK_q:
      return 0x11ba;    /* jongseong sios */
    case GDK_2:
      return 0x11bb;    /* jongseong ssangsios */
    case GDK_A:
    case GDK_a:
      return 0x11bc;    /* jongseong ieung */
    case GDK_minus:
      return 0x11bd;    /* jongseong cieuc */
    case GDK_equal:
      return 0x11be;    /* jongseong chieuch */
    case GDK_backslash:
      return 0x11bf;    /* jongseong khieukh */
    case GDK_bracketleft:
      return 0x11c0;    /* jongseong thieuth */
    case GDK_bracketright:
      return 0x11c1;    /* jongseong phieuph */
    case GDK_1:
      return 0x11c2;    /* jongseong hieuh */
  }
  return 0;
}

/* return unicode jamo jongseong value(U+11a8 ~ U+11c2) in 3bul keyboard
 * if it is not hangul key, return 0 */
static gunichar
im_hangul3_comp_jongseong_sun(gunichar ch, guint keyval, guint state)
{
  if (is_set(state, GDK_SHIFT_MASK))
    return 0;
  switch (ch) {
    case 0x11a8:		/* jongseong kiyeok */
      switch (keyval) {
        case GDK_X:
        case GDK_x:
          return 0x11a9;	/* jongseong ssangkiyeok */
        case GDK_Q:
        case GDK_q:
          return 0x11aa;	/* jongseong kiyeok-sios */
      }
      break;
    case 0x11ab:		/* jongseong nieun */
      switch (keyval) {
	case GDK_minus:
          return 0x11ac;	/* jongseong nieun-cieuc */
        case GDK_1:
          return 0x11ad;	/* jongseong nieun-hieuh */
      }
      break;
    case 0x11af:		/* jongseong rieul */
      switch (keyval) {
        case GDK_X:
        case GDK_x:
          return 0x11b0;	/* jongseong rieul-kiyeok */
        case GDK_Z:
        case GDK_z:
          return 0x11b1;	/* jongseong rieul-mieum */
        case GDK_3:
          return 0x11b2;	/* jongseong rieul-pieup */
        case GDK_Q:
        case GDK_q:
          return 0x11b3;	/* jongseong rieul-sios */
	case GDK_bracketleft:
          return 0x11b4;	/* jongseong rieul-thieuth */
	case GDK_bracketright:
          return 0x11b5;	/* jongseong rieul-phieuph */
        case GDK_1:
          return 0x11b6;	/* jongseong rieul-hieuh */
      }
      break;
    case 0x11b8:		/* jongseong pieup */
      switch (keyval) {
        case GDK_Q:
        case GDK_q:
          return 0x11b9;	/* jongseong pieup-sios */
      }
      break;
    case 0x11ba:		/* jongseong sios */
      switch (keyval) {
        case GDK_Q:
        case GDK_q:
          return 0x11bb;	/* jongseong ssangsios */
      }
  }
  return 0;
}

/* return unicode number and punctuation value in 3bul keyboard
 * if it is not hangul key, return 0 */
static gunichar
im_hangul3_punct_sun(guint keyval, guint state)
{
  if (is_set(state, GDK_SHIFT_MASK)) {
    switch (keyval) {
      case GDK_N:
      case GDK_n:
        return 0x0030;	/* 0 */
      case GDK_M:           
      case GDK_m:           
        return 0x0031;	/* 1 */
      case GDK_less:           
        return 0x0032;	/* 2 */
      case GDK_greater:           
        return 0x0033;	/* 3 */
      case GDK_J:         
      case GDK_j:         
        return 0x0034;	/* 4 */
      case GDK_K:           
      case GDK_k:           
        return 0x0035;	/* 5 */
      case GDK_L:           
      case GDK_l:           
        return 0x0036;	/* 6 */
      case GDK_U:           
      case GDK_u:           
        return 0x0037;	/* 7 */
      case GDK_I:           
      case GDK_i:           
        return 0x0038;	/* 8 */
      case GDK_O:           
      case GDK_o:           
        return 0x0039;	/* 9 */
      case GDK_B:           
      case GDK_b:           
        return 0x0021;	/* exclamation mark */
      case GDK_P:           
      case GDK_p:           
        return 0x003e;	/* greater-than sign */
      case GDK_Y:           
      case GDK_y:           
        return 0x003c;	/* less-than sign */
      case GDK_T:           
      case GDK_t:           
        return 0x003b;	/* semicolon */
      case GDK_G:           
      case GDK_g:           
        return 0x002f;	/* slash */
      case GDK_H:           
      case GDK_h:           
        return 0x0027;	/* apostrophe */
    }
  }
  return 0;
}

void
im_module_init(GTypeModule *type_module)
{
  im_hangul_register_type(type_module, "GtkIMContextHangul3s");
}

void
im_module_exit(void)
{
  im_hangul_shutdown();
}

void
im_module_list (const GtkIMContextInfo ***contexts,
		int *n_contexts)
{
  *contexts = info_list;
  *n_contexts = G_N_ELEMENTS(info_list);
}

GtkIMContext *
im_module_create (const gchar *context_id)
{
  if (strcmp (context_id, "hangul3s") == 0) {
    GtkIMContext *context = im_hangul_new();
    if (context) {
      GtkIMContextHangul *context_hangul = GTK_IM_CONTEXT_HANGUL(context);
      im_hangul_set_automata(context_hangul, im_hangul3_automata);

      im_hangul3_choseong = im_hangul3_choseong_sun;
      im_hangul3_jungseong = im_hangul3_jungseong_sun;
      im_hangul3_jongseong = im_hangul3_jongseong_sun;
      im_hangul3_punct = im_hangul3_punct_sun;
      im_hangul3_comp_choseong = im_hangul3_comp_choseong_sun;
      im_hangul3_comp_jungseong = im_hangul3_comp_jungseong_sun;
      im_hangul3_comp_jongseong = im_hangul3_comp_jongseong_sun;

      return context;
    }
  }
  return NULL;
}

/* vim: nocindent
 */
