/**************************************************************************
--           PICO2 RISC-V Sierpinski timing
-- 
--           Copyright (C) 2025 By Ulrik Hørlyk Hjort
--
--  This Program is Free Software; You Can Redistribute It and/or
--  Modify It Under The Terms of The GNU General Public License
--  As Published By The Free Software Foundation; Either Version 2
--  of The License, or (at Your Option) Any Later Version.
--
--  This Program is Distributed in The Hope That It Will Be Useful,
--  But WITHOUT ANY WARRANTY; Without Even The Implied Warranty of
--  MERCHANTABILITY or FITNESS for A PARTICULAR PURPOSE.  See The
--  GNU General Public License for More Details.
--
-- You Should Have Received A Copy of The GNU General Public License
-- Along with This Program; if not, See <Http://Www.Gnu.Org/Licenses/>.
***************************************************************************/
#ifndef INC_TIMING_H_
#define INC_TIMING_H_

absolute_time_t start_global = 0;

#define TIME_START() start_global = get_absolute_time();
#define TIME_US_STOP(label)	printf("%s: %lld us\r\n", label, (absolute_time_diff_us(start_global, get_absolute_time()))); 
#define TIME_MS_STOP(label)	printf("%s: %lld ms\r\n", label, (absolute_time_diff_us(start_global, get_absolute_time()) / 1000)); 

#define TIME_MEASURE_US(func) \
{                             \
 absolute_time_t start_local = get_absolute_time(); \
 func;    \
 printf(#func ": %lld us\r\n", absolute_time_diff_us(start_local, get_absolute_time())); \
}

#define TIME_MEASURE_MS(func) \
{                             \
 absolute_time_t start_local = get_absolute_time(); \
 func;                 \
 printf(#func ": %lld ms\r\n", (absolute_time_diff_us(start_local, get_absolute_time()) / 1000));	 \
}

#endif /* INC_TIMING_H_ */
