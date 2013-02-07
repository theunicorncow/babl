#include <stdlib.h>
#include <stdint.h>
#include "babl.h"

int init (void);

static inline long
float_to_u8 (unsigned char *src_char, unsigned char *dst, long samples)
{
  float *src = (float *)src_char;
  long n = samples * 4;
  while (n--)
    {
      if (*src >= 1.0)
      {
        *dst++ = 0xFF;
        src++;
      }
      else if (*src <= 0.0)
      {
        *dst++ = 0x0;
        src++;
      }
      else
        *dst++ = 0xFF * *src++ + 0.5;
    }
  return samples;
}

static inline long
float_to_u16 (unsigned char *src_char, unsigned char *dst_char, long samples)
{
  float *src    = (float *)src_char;
  uint16_t *dst = (uint16_t *)dst_char;
  long n = samples * 4;
  while (n--)
    {
      if (*src >= 1.0)
      {
        *dst++ = 0xFFFF;
        src++;
      }
      else if (*src <= 0.0)
      {
        *dst++ = 0x0;
        src++;
      }
      else
        *dst++ = 0xFFFF * *src++ + 0.5;
    }
  return samples;
}

int
init (void)
{
  babl_conversion_new (babl_format ("R'aG'aB'aA float"),
                       babl_format ("R'aG'aB'aA u8"),
                      "linear", 
                       float_to_u8,
                       NULL);
  babl_conversion_new (babl_format ("R'G'B'A float"),
                       babl_format ("R'G'B'A u8"),
                      "linear", 
                       float_to_u8,
                       NULL);
  babl_conversion_new (babl_format ("RGBA float"),
                       babl_format ("RGBA u8"),
                      "linear", 
                       float_to_u8,
                       NULL);
  babl_conversion_new (babl_format ("RaGaBaA float"),
                       babl_format ("RaGaBaA u8"),
                      "linear", 
                       float_to_u8,
                       NULL);
                       
  babl_conversion_new (babl_format ("R'aG'aB'aA float"),
                       babl_format ("R'aG'aB'aA u16"),
                      "linear", 
                       float_to_u16,
                       NULL);
  babl_conversion_new (babl_format ("R'G'B'A float"),
                       babl_format ("R'G'B'A u16"),
                      "linear", 
                       float_to_u16,
                       NULL);
  babl_conversion_new (babl_format ("RGBA float"),
                       babl_format ("RGBA u16"),
                      "linear", 
                       float_to_u16,
                       NULL);
  babl_conversion_new (babl_format ("RaGaBaA float"),
                       babl_format ("RaGaBaA u16"),
                      "linear", 
                       float_to_u16,
                       NULL);

  return 0;
}