#include "hls_target.h"

#include "Linebuffer.h"

inline int8_t abs_i8(int8_t a) {return a >= 0 ? a : -a;}
inline int16_t abs_i16(int16_t a) {return a >= 0 ? a : -a;}
inline int32_t abs_i32(int32_t a) {return a >= 0 ? a : -a;}
inline int64_t abs_i64(int64_t a) {return a >= 0 ? a : -a;}

template<typename T> T max(T a, T b) {if (a > b) return a; return b;}
template<typename T> T min(T a, T b) {if (a < b) return a; return b;}
template<typename T> T smod(T a, T b) {T result = a % b; if (result < 0) result += b < 0 ? -b : b; return result;}
template<typename T> T sdiv(T a, T b) {T q = a / b; T r = a - q*b; int bs = b >> (8*sizeof(T) - 1); int rs = r >> (8*sizeof(T) - 1); return q - (rs & bs) + (rs & ~bs);}

void _hls_target_hw_output__2_stencil_stream(
hls::stream<Stencil<uint8_t, 8, 8> > &_hw_output__2_stencil_stream,
hls::stream<Stencil<uint16_t, 8, 8> > &_input2__2_stencil_update_stream,
hls::stream<Stencil<uint8_t, 8, 8> > &_repeat_edge__2_stencil_update_stream)
{
 {
  hls::stream<Stencil<uint8_t, 8, 8> > _repeat_edge__2_stencil_stream;
  // produce repeat_edge$2.stencil.stream
  linebuffer<296, 296>(_repeat_edge__2_stencil_update_stream, _repeat_edge__2_stencil_stream);
  (void)0;
  // consume repeat_edge$2.stencil.stream
  {
   hls::stream<Stencil<uint16_t, 1, 1, 13, 2> > _histogram__2_stencil_stream;
   // produce histogram$2.stencil.stream
   for (int _blurz__2_scan_update_y = 0; _blurz__2_scan_update_y < 0 + 37; _blurz__2_scan_update_y++)
   {
    for (int _blurz__2_scan_update_x = 0; _blurz__2_scan_update_x < 0 + 37; _blurz__2_scan_update_x++)
    {
     {
      Stencil<uint8_t, 8, 8> _repeat_edge__2_stencil;
      // produce repeat_edge$2.stencil
      _repeat_edge__2_stencil = _repeat_edge__2_stencil_stream.read();
      (void)0;
      // consume repeat_edge$2.stencil
      {
       Stencil<uint16_t, 1, 1, 13, 2> _histogram__2_stencil;
       // produce histogram$2.stencil
       for (int _histogram__2_stencil_s0_z = 0; _histogram__2_stencil_s0_z < 0 + 13; _histogram__2_stencil_s0_z++)
       {
        for (int _histogram__2_stencil_s0_c = 0; _histogram__2_stencil_s0_c < 0 + 2; _histogram__2_stencil_s0_c++)
        {
         uint16_t _212 = (uint16_t)(0);
         _histogram__2_stencil(0, 0, _histogram__2_stencil_s0_z, _histogram__2_stencil_s0_c) = _212;
        } // for _histogram__2_stencil_s0_c
       } // for _histogram__2_stencil_s0_z
       // update histogram$2.stencil
       for (int _histogram__2_s1_p2___r_y__r = 0; _histogram__2_s1_p2___r_y__r < 0 + 8; _histogram__2_s1_p2___r_y__r++)
       {
        for (int _histogram__2_s1_p2___r_x__r = 0; _histogram__2_s1_p2___r_x__r < 0 + 8; _histogram__2_s1_p2___r_x__r++)
        {
         for (int _histogram__2_stencil_s1_c = 0; _histogram__2_stencil_s1_c < 0 + 2; _histogram__2_stencil_s1_c++)
         {
          uint8_t _213 = _repeat_edge__2_stencil(_histogram__2_s1_p2___r_x__r, _histogram__2_s1_p2___r_y__r);
          uint8_t _214 = (uint8_t)(16);
          uint8_t _215 = _213 + _214;
          uint8_t _216 = _215 >> 5;
          int32_t _217 = (int32_t)(_216);
          int32_t _218 = _217 + 2;
          uint16_t _219 = _histogram__2_stencil(0, 0, _218, _histogram__2_stencil_s1_c);
          uint8_t _220 = _213 >> 4;
          uint8_t _221 = (uint8_t)(4);
          bool _222 = _histogram__2_stencil_s1_c == 0;
          uint8_t _223 = (uint8_t)(_222 ? _220 : _221);
          uint16_t _224 = (uint16_t)(_223);
          uint16_t _225 = _219 + _224;
          _histogram__2_stencil(0, 0, _218, _histogram__2_stencil_s1_c) = _225;
         } // for _histogram__2_stencil_s1_c
        } // for _histogram__2_s1_p2___r_x__r
       } // for _histogram__2_s1_p2___r_y__r
       // consume histogram$2.stencil
       _histogram__2_stencil_stream.write(_histogram__2_stencil);
       (void)0;
      } // realize _histogram__2_stencil
     } // realize _repeat_edge__2_stencil
    } // for _blurz__2_scan_update_x
   } // for _blurz__2_scan_update_y
   // consume histogram$2.stencil.stream
   {
    hls::stream<Stencil<uint16_t, 1, 1, 9, 2> > _blurz__2_stencil_update_stream;
    // produce blurz$2.stencil_update.stream
    for (int _blurz__2_scan_update_y = 0; _blurz__2_scan_update_y < 0 + 37; _blurz__2_scan_update_y++)
    {
     for (int _blurz__2_scan_update_x = 0; _blurz__2_scan_update_x < 0 + 37; _blurz__2_scan_update_x++)
     {
      {
       Stencil<uint16_t, 1, 1, 13, 2> _histogram__2_stencil;
       // produce histogram$2.stencil
       _histogram__2_stencil = _histogram__2_stencil_stream.read();
       (void)0;
       // consume histogram$2.stencil
       {
        Stencil<uint16_t, 1, 1, 9, 2> _blurz__2_stencil;
        // produce blurz$2.stencil
        for (int _blurz__2_stencil_s0_c = 0; _blurz__2_stencil_s0_c < 0 + 2; _blurz__2_stencil_s0_c++)
        {
         for (int _blurz__2_stencil_s0_z = 0; _blurz__2_stencil_s0_z < 0 + 9; _blurz__2_stencil_s0_z++)
         {
          uint16_t _226 = _histogram__2_stencil(0, 0, _blurz__2_stencil_s0_z, _blurz__2_stencil_s0_c);
          int32_t _227 = _blurz__2_stencil_s0_z + 1;
          uint16_t _228 = _histogram__2_stencil(0, 0, _227, _blurz__2_stencil_s0_c);
          uint16_t _229 = (uint16_t)(4);
          uint16_t _230 = _228 * _229;
          uint16_t _231 = _226 + _230;
          int32_t _232 = _blurz__2_stencil_s0_z + 2;
          uint16_t _233 = _histogram__2_stencil(0, 0, _232, _blurz__2_stencil_s0_c);
          uint16_t _234 = (uint16_t)(6);
          uint16_t _235 = _233 * _234;
          uint16_t _236 = _231 + _235;
          int32_t _237 = _blurz__2_stencil_s0_z + 3;
          uint16_t _238 = _histogram__2_stencil(0, 0, _237, _blurz__2_stencil_s0_c);
          uint16_t _239 = _238 * _229;
          uint16_t _240 = _236 + _239;
          int32_t _241 = _blurz__2_stencil_s0_z + 4;
          uint16_t _242 = _histogram__2_stencil(0, 0, _241, _blurz__2_stencil_s0_c);
          uint16_t _243 = _240 + _242;
          uint16_t _244 = _243 >> 4;
          _blurz__2_stencil(0, 0, _blurz__2_stencil_s0_z, _blurz__2_stencil_s0_c) = _244;
         } // for _blurz__2_stencil_s0_z
        } // for _blurz__2_stencil_s0_c
        // consume blurz$2.stencil
        _blurz__2_stencil_update_stream.write(_blurz__2_stencil);
        (void)0;
       } // realize _blurz__2_stencil
      } // realize _histogram__2_stencil
     } // for _blurz__2_scan_update_x
    } // for _blurz__2_scan_update_y
    // consume blurz$2.stencil_update.stream
    {
     hls::stream<Stencil<uint16_t, 5, 1, 9, 2> > _blurz__2_stencil_stream;
     // produce blurz$2.stencil.stream
     linebuffer<37, 37, 9, 2>(_blurz__2_stencil_update_stream, _blurz__2_stencil_stream);
     (void)0;
     // consume blurz$2.stencil.stream
     {
      hls::stream<Stencil<uint16_t, 1, 1, 9, 2> > _blurx__2_stencil_update_stream;
      // produce blurx$2.stencil_update.stream
      for (int _blurx__2_scan_update_y = 0; _blurx__2_scan_update_y < 0 + 37; _blurx__2_scan_update_y++)
      {
       for (int _blurx__2_scan_update_x = 0; _blurx__2_scan_update_x < 0 + 33; _blurx__2_scan_update_x++)
       {
        {
         Stencil<uint16_t, 5, 1, 9, 2> _blurz__2_stencil;
         // produce blurz$2.stencil
         _blurz__2_stencil = _blurz__2_stencil_stream.read();
         (void)0;
         // consume blurz$2.stencil
         {
          Stencil<uint16_t, 1, 1, 9, 2> _blurx__2_stencil;
          // produce blurx$2.stencil
          for (int _blurx__2_stencil_s0_c = 0; _blurx__2_stencil_s0_c < 0 + 2; _blurx__2_stencil_s0_c++)
          {
           for (int _blurx__2_stencil_s0_z = 0; _blurx__2_stencil_s0_z < 0 + 9; _blurx__2_stencil_s0_z++)
           {
            uint16_t _245 = _blurz__2_stencil(0, 0, _blurx__2_stencil_s0_z, _blurx__2_stencil_s0_c);
            uint16_t _246 = _blurz__2_stencil(1, 0, _blurx__2_stencil_s0_z, _blurx__2_stencil_s0_c);
            uint16_t _247 = (uint16_t)(4);
            uint16_t _248 = _246 * _247;
            uint16_t _249 = _245 + _248;
            uint16_t _250 = _blurz__2_stencil(2, 0, _blurx__2_stencil_s0_z, _blurx__2_stencil_s0_c);
            uint16_t _251 = (uint16_t)(6);
            uint16_t _252 = _250 * _251;
            uint16_t _253 = _249 + _252;
            uint16_t _254 = _blurz__2_stencil(3, 0, _blurx__2_stencil_s0_z, _blurx__2_stencil_s0_c);
            uint16_t _255 = _254 * _247;
            uint16_t _256 = _253 + _255;
            uint16_t _257 = _blurz__2_stencil(4, 0, _blurx__2_stencil_s0_z, _blurx__2_stencil_s0_c);
            uint16_t _258 = _256 + _257;
            uint16_t _259 = _258 >> 4;
            _blurx__2_stencil(0, 0, _blurx__2_stencil_s0_z, _blurx__2_stencil_s0_c) = _259;
           } // for _blurx__2_stencil_s0_z
          } // for _blurx__2_stencil_s0_c
          // consume blurx$2.stencil
          _blurx__2_stencil_update_stream.write(_blurx__2_stencil);
          (void)0;
         } // realize _blurx__2_stencil
        } // realize _blurz__2_stencil
       } // for _blurx__2_scan_update_x
      } // for _blurx__2_scan_update_y
      // consume blurx$2.stencil_update.stream
      {
       hls::stream<Stencil<uint16_t, 1, 5, 9, 2> > _blurx__2_stencil_stream;
       // produce blurx$2.stencil.stream
       linebuffer<33, 37, 9, 2>(_blurx__2_stencil_update_stream, _blurx__2_stencil_stream);
       (void)0;
       // consume blurx$2.stencil.stream
       {
        hls::stream<Stencil<uint16_t, 1, 1, 9, 2> > _blury__2_stencil_update_stream;
        // produce blury$2.stencil_update.stream
        for (int _blury__2_scan_update_y = 0; _blury__2_scan_update_y < 0 + 33; _blury__2_scan_update_y++)
        {
         for (int _blury__2_scan_update_x = 0; _blury__2_scan_update_x < 0 + 33; _blury__2_scan_update_x++)
         {
          {
           Stencil<uint16_t, 1, 5, 9, 2> _blurx__2_stencil;
           // produce blurx$2.stencil
           _blurx__2_stencil = _blurx__2_stencil_stream.read();
           (void)0;
           // consume blurx$2.stencil
           {
            Stencil<uint16_t, 1, 1, 9, 2> _blury__2_stencil;
            // produce blury$2.stencil
            for (int _blury__2_stencil_s0_c = 0; _blury__2_stencil_s0_c < 0 + 2; _blury__2_stencil_s0_c++)
            {
             for (int _blury__2_stencil_s0_z = 0; _blury__2_stencil_s0_z < 0 + 9; _blury__2_stencil_s0_z++)
             {
              uint16_t _260 = _blurx__2_stencil(0, 0, _blury__2_stencil_s0_z, _blury__2_stencil_s0_c);
              uint16_t _261 = _blurx__2_stencil(0, 1, _blury__2_stencil_s0_z, _blury__2_stencil_s0_c);
              uint16_t _262 = (uint16_t)(4);
              uint16_t _263 = _261 * _262;
              uint16_t _264 = _260 + _263;
              uint16_t _265 = _blurx__2_stencil(0, 2, _blury__2_stencil_s0_z, _blury__2_stencil_s0_c);
              uint16_t _266 = (uint16_t)(6);
              uint16_t _267 = _265 * _266;
              uint16_t _268 = _264 + _267;
              uint16_t _269 = _blurx__2_stencil(0, 3, _blury__2_stencil_s0_z, _blury__2_stencil_s0_c);
              uint16_t _270 = _269 * _262;
              uint16_t _271 = _268 + _270;
              uint16_t _272 = _blurx__2_stencil(0, 4, _blury__2_stencil_s0_z, _blury__2_stencil_s0_c);
              uint16_t _273 = _271 + _272;
              uint16_t _274 = _273 >> 4;
              _blury__2_stencil(0, 0, _blury__2_stencil_s0_z, _blury__2_stencil_s0_c) = _274;
             } // for _blury__2_stencil_s0_z
            } // for _blury__2_stencil_s0_c
            // consume blury$2.stencil
            _blury__2_stencil_update_stream.write(_blury__2_stencil);
            (void)0;
           } // realize _blury__2_stencil
          } // realize _blurx__2_stencil
         } // for _blury__2_scan_update_x
        } // for _blury__2_scan_update_y
        // consume blury$2.stencil_update.stream
        {
         hls::stream<Stencil<uint16_t, 2, 2, 9, 2> > _blury__2_stencil_stream;
         // produce blury$2.stencil.stream
         linebuffer<33, 33, 9, 2>(_blury__2_stencil_update_stream, _blury__2_stencil_stream);
         (void)0;
         // consume blury$2.stencil.stream
         {
          hls::stream<Stencil<uint16_t, 8, 8> > _input2__2_stencil_stream;
          // produce input2$2.stencil.stream
          linebuffer<256, 256>(_input2__2_stencil_update_stream, _input2__2_stencil_stream);
          (void)0;
          // consume input2$2.stencil.stream
          for (int _output__2_s0_y_y_in_y_grid = 0; _output__2_s0_y_y_in_y_grid < 0 + 32; _output__2_s0_y_y_in_y_grid++)
          {
           for (int _output__2_s0_x_x_in_x_grid = 0; _output__2_s0_x_x_in_x_grid < 0 + 32; _output__2_s0_x_x_in_x_grid++)
           {
            {
             Stencil<uint16_t, 8, 8> _input2__2_stencil;
             // produce input2$2.stencil
             _input2__2_stencil = _input2__2_stencil_stream.read();
             (void)0;
             // consume input2$2.stencil
             {
              Stencil<uint16_t, 2, 2, 9, 2> _blury__2_stencil;
              // produce blury$2.stencil
              _blury__2_stencil = _blury__2_stencil_stream.read();
              (void)0;
              // consume blury$2.stencil
              {
               Stencil<uint8_t, 8, 8> _hw_output__2_stencil;
               // produce hw_output$2.stencil
               for (int _hw_output__2_stencil_s0_y = 0; _hw_output__2_stencil_s0_y < 0 + 8; _hw_output__2_stencil_s0_y++)
               {
                for (int _hw_output__2_stencil_s0_x = 0; _hw_output__2_stencil_s0_x < 0 + 8; _hw_output__2_stencil_s0_x++)
                {
                 uint16_t _275 = _input2__2_stencil(_hw_output__2_stencil_s0_x, _hw_output__2_stencil_s0_y);
                 uint16_t _276 = _275 >> 5;
                 int32_t _277 = (int32_t)(_276);
                 uint16_t _278 = _blury__2_stencil(0, 0, _277, 1);
                 uint32_t _279 = (uint32_t)(_278);
                 uint16_t _280 = (uint16_t)(65535);
                 int32_t _281 = _hw_output__2_stencil_s0_x * 8192;
                 uint16_t _282 = (uint16_t)(_281);
                 uint16_t _283 = _280 - _282;
                 uint32_t _284 = (uint32_t)(_283);
                 uint32_t _285 = _279 * _284;
                 uint16_t _286 = _blury__2_stencil(1, 0, _277, 1);
                 uint32_t _287 = (uint32_t)(_286);
                 uint32_t _288 = (uint32_t)(_282);
                 uint32_t _289 = _287 * _288;
                 uint32_t _290 = _285 + _289;
                 uint32_t _291 = (uint32_t)(32768);
                 uint32_t _292 = _290 + _291;
                 uint32_t _293 = _292 >> 16;
                 uint32_t _294 = _293 + _290;
                 uint32_t _295 = _294 + _291;
                 uint32_t _296 = _295 >> 16;
                 uint16_t _297 = (uint16_t)(_296);
                 uint16_t _298 = _297;
                 uint32_t _299 = (uint32_t)(_298);
                 int32_t _300 = _hw_output__2_stencil_s0_y * 8192;
                 uint16_t _301 = (uint16_t)(_300);
                 uint16_t _302 = _280 - _301;
                 uint32_t _303 = (uint32_t)(_302);
                 uint32_t _304 = _299 * _303;
                 uint16_t _305 = _blury__2_stencil(0, 1, _277, 1);
                 uint32_t _306 = (uint32_t)(_305);
                 uint32_t _307 = _306 * _284;
                 uint16_t _308 = _blury__2_stencil(1, 1, _277, 1);
                 uint32_t _309 = (uint32_t)(_308);
                 uint32_t _310 = _309 * _288;
                 uint32_t _311 = _307 + _310;
                 uint32_t _312 = _311 + _291;
                 uint32_t _313 = _312 >> 16;
                 uint32_t _314 = _313 + _311;
                 uint32_t _315 = _314 + _291;
                 uint32_t _316 = _315 >> 16;
                 uint16_t _317 = (uint16_t)(_316);
                 uint16_t _318 = _317;
                 uint32_t _319 = (uint32_t)(_318);
                 uint32_t _320 = (uint32_t)(_301);
                 uint32_t _321 = _319 * _320;
                 uint32_t _322 = _304 + _321;
                 uint32_t _323 = _322 + _291;
                 uint32_t _324 = _323 >> 16;
                 uint32_t _325 = _324 + _322;
                 uint32_t _326 = _325 + _291;
                 uint32_t _327 = _326 >> 16;
                 uint16_t _328 = (uint16_t)(_327);
                 uint16_t _329 = _328;
                 uint32_t _330 = (uint32_t)(_329);
                 uint16_t _331 = _275 & 31;
                 uint16_t _332 = (uint16_t)(2048);
                 uint16_t _333 = _331 * _332;
                 uint16_t _334 = _280 - _333;
                 uint32_t _335 = (uint32_t)(_334);
                 uint32_t _336 = _330 * _335;
                 int32_t _337 = _277 + 1;
                 uint16_t _338 = _blury__2_stencil(0, 0, _337, 1);
                 uint32_t _339 = (uint32_t)(_338);
                 uint32_t _340 = _339 * _284;
                 uint16_t _341 = _blury__2_stencil(1, 0, _337, 1);
                 uint32_t _342 = (uint32_t)(_341);
                 uint32_t _343 = _342 * _288;
                 uint32_t _344 = _340 + _343;
                 uint32_t _345 = _344 + _291;
                 uint32_t _346 = _345 >> 16;
                 uint32_t _347 = _346 + _344;
                 uint32_t _348 = _347 + _291;
                 uint32_t _349 = _348 >> 16;
                 uint16_t _350 = (uint16_t)(_349);
                 uint16_t _351 = _350;
                 uint32_t _352 = (uint32_t)(_351);
                 uint32_t _353 = _352 * _303;
                 uint16_t _354 = _blury__2_stencil(0, 1, _337, 1);
                 uint32_t _355 = (uint32_t)(_354);
                 uint32_t _356 = _355 * _284;
                 uint16_t _357 = _blury__2_stencil(1, 1, _337, 1);
                 uint32_t _358 = (uint32_t)(_357);
                 uint32_t _359 = _358 * _288;
                 uint32_t _360 = _356 + _359;
                 uint32_t _361 = _360 + _291;
                 uint32_t _362 = _361 >> 16;
                 uint32_t _363 = _362 + _360;
                 uint32_t _364 = _363 + _291;
                 uint32_t _365 = _364 >> 16;
                 uint16_t _366 = (uint16_t)(_365);
                 uint16_t _367 = _366;
                 uint32_t _368 = (uint32_t)(_367);
                 uint32_t _369 = _368 * _320;
                 uint32_t _370 = _353 + _369;
                 uint32_t _371 = _370 + _291;
                 uint32_t _372 = _371 >> 16;
                 uint32_t _373 = _372 + _370;
                 uint32_t _374 = _373 + _291;
                 uint32_t _375 = _374 >> 16;
                 uint16_t _376 = (uint16_t)(_375);
                 uint16_t _377 = _376;
                 uint32_t _378 = (uint32_t)(_377);
                 uint32_t _379 = (uint32_t)(_333);
                 uint32_t _380 = _378 * _379;
                 uint32_t _381 = _336 + _380;
                 uint32_t _382 = _381 + _291;
                 uint32_t _383 = _382 >> 16;
                 uint32_t _384 = _383 + _381;
                 uint32_t _385 = _384 + _291;
                 uint32_t _386 = _385 >> 16;
                 uint16_t _387 = (uint16_t)(_386);
                 uint16_t _388 = _387;
                 uint16_t _389 = (uint16_t)(0);
                 uint16_t _390 = _blury__2_stencil(0, 0, _277, 0);
                 uint32_t _391 = (uint32_t)(_390);
                 uint32_t _392 = _391 * _284;
                 uint16_t _393 = _blury__2_stencil(1, 0, _277, 0);
                 uint32_t _394 = (uint32_t)(_393);
                 uint32_t _395 = _394 * _288;
                 uint32_t _396 = _392 + _395;
                 uint32_t _397 = _396 + _291;
                 uint32_t _398 = _397 >> 16;
                 uint32_t _399 = _398 + _396;
                 uint32_t _400 = _399 + _291;
                 uint32_t _401 = _400 >> 16;
                 uint16_t _402 = (uint16_t)(_401);
                 uint16_t _403 = _402;
                 uint32_t _404 = (uint32_t)(_403);
                 uint32_t _405 = _404 * _303;
                 uint16_t _406 = _blury__2_stencil(0, 1, _277, 0);
                 uint32_t _407 = (uint32_t)(_406);
                 uint32_t _408 = _407 * _284;
                 uint16_t _409 = _blury__2_stencil(1, 1, _277, 0);
                 uint32_t _410 = (uint32_t)(_409);
                 uint32_t _411 = _410 * _288;
                 uint32_t _412 = _408 + _411;
                 uint32_t _413 = _412 + _291;
                 uint32_t _414 = _413 >> 16;
                 uint32_t _415 = _414 + _412;
                 uint32_t _416 = _415 + _291;
                 uint32_t _417 = _416 >> 16;
                 uint16_t _418 = (uint16_t)(_417);
                 uint16_t _419 = _418;
                 uint32_t _420 = (uint32_t)(_419);
                 uint32_t _421 = _420 * _320;
                 uint32_t _422 = _405 + _421;
                 uint32_t _423 = _422 + _291;
                 uint32_t _424 = _423 >> 16;
                 uint32_t _425 = _424 + _422;
                 uint32_t _426 = _425 + _291;
                 uint32_t _427 = _426 >> 16;
                 uint16_t _428 = (uint16_t)(_427);
                 uint16_t _429 = _428;
                 uint32_t _430 = (uint32_t)(_429);
                 uint32_t _431 = _430 * _335;
                 uint16_t _432 = _blury__2_stencil(0, 0, _337, 0);
                 uint32_t _433 = (uint32_t)(_432);
                 uint32_t _434 = _433 * _284;
                 uint16_t _435 = _blury__2_stencil(1, 0, _337, 0);
                 uint32_t _436 = (uint32_t)(_435);
                 uint32_t _437 = _436 * _288;
                 uint32_t _438 = _434 + _437;
                 uint32_t _439 = _438 + _291;
                 uint32_t _440 = _439 >> 16;
                 uint32_t _441 = _440 + _438;
                 uint32_t _442 = _441 + _291;
                 uint32_t _443 = _442 >> 16;
                 uint16_t _444 = (uint16_t)(_443);
                 uint16_t _445 = _444;
                 uint32_t _446 = (uint32_t)(_445);
                 uint32_t _447 = _446 * _303;
                 uint16_t _448 = _blury__2_stencil(0, 1, _337, 0);
                 uint32_t _449 = (uint32_t)(_448);
                 uint32_t _450 = _449 * _284;
                 uint16_t _451 = _blury__2_stencil(1, 1, _337, 0);
                 uint32_t _452 = (uint32_t)(_451);
                 uint32_t _453 = _452 * _288;
                 uint32_t _454 = _450 + _453;
                 uint32_t _455 = _454 + _291;
                 uint32_t _456 = _455 >> 16;
                 uint32_t _457 = _456 + _454;
                 uint32_t _458 = _457 + _291;
                 uint32_t _459 = _458 >> 16;
                 uint16_t _460 = (uint16_t)(_459);
                 uint16_t _461 = _460;
                 uint32_t _462 = (uint32_t)(_461);
                 uint32_t _463 = _462 * _320;
                 uint32_t _464 = _447 + _463;
                 uint32_t _465 = _464 + _291;
                 uint32_t _466 = _465 >> 16;
                 uint32_t _467 = _466 + _464;
                 uint32_t _468 = _467 + _291;
                 uint32_t _469 = _468 >> 16;
                 uint16_t _470 = (uint16_t)(_469);
                 uint16_t _471 = _470;
                 uint32_t _472 = (uint32_t)(_471);
                 uint32_t _473 = _472 * _379;
                 uint32_t _474 = _431 + _473;
                 uint32_t _475 = _474 + _291;
                 uint32_t _476 = _475 >> 16;
                 uint32_t _477 = _476 + _474;
                 uint32_t _478 = _477 + _291;
                 uint32_t _479 = _478 >> 16;
                 uint16_t _480 = (uint16_t)(_479);
                 uint16_t _481 = _480;
                 uint16_t _482 = (uint16_t)(64);
                 uint16_t _483 = _481 * _482;
                 uint16_t _484 = _483 / _388;
                 uint16_t _485 = (uint16_t)(255);
                 uint16_t _486 = min(_484, _485);
                 bool _487 = _388 == _389;
                 uint16_t _488 = (uint16_t)(_487 ? _389 : _486);
                 uint8_t _489 = (uint8_t)(_488);
                 _hw_output__2_stencil(_hw_output__2_stencil_s0_x, _hw_output__2_stencil_s0_y) = _489;
                } // for _hw_output__2_stencil_s0_x
               } // for _hw_output__2_stencil_s0_y
               // consume hw_output$2.stencil
               _hw_output__2_stencil_stream.write(_hw_output__2_stencil);
               (void)0;
              } // realize _hw_output__2_stencil
             } // realize _blury__2_stencil
            } // realize _input2__2_stencil
           } // for _output__2_s0_x_x_in_x_grid
          } // for _output__2_s0_y_y_in_y_grid
         } // realize _input2__2_stencil_stream
        } // realize _blury__2_stencil_stream
       } // realize _blury__2_stencil_update_stream
      } // realize _blurx__2_stencil_stream
     } // realize _blurx__2_stencil_update_stream
    } // realize _blurz__2_stencil_stream
   } // realize _blurz__2_stencil_update_stream
  } // realize _histogram__2_stencil_stream
 } // realize _repeat_edge__2_stencil_stream
} // kernel hls_target_hls_target_hw_output__2_stencil_stream

