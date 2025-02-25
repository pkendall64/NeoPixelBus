/*-------------------------------------------------------------------------
NeoColorFeatures provides feature classes to describe color order and
color depth for NeoPixelBus template class

Written by Michael C. Miller.

I invest time and resources providing this open source code,
please support me by dontating (see https://github.com/Makuna/NeoPixelBus)

-------------------------------------------------------------------------
This file is part of the Makuna/NeoPixelBus library.

NeoPixelBus is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

NeoPixelBus is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with NeoPixel.  If not, see
<http://www.gnu.org/licenses/>.
-------------------------------------------------------------------------*/
#pragma once

class Neo3ByteElements
{
public:
    static const size_t PixelSize = 3;

    static uint8_t* getPixelAddress(uint8_t* pPixels, uint16_t indexPixel) 
    {
        return pPixels + indexPixel * PixelSize;
    }
    static const uint8_t* getPixelAddress(const uint8_t* pPixels, uint16_t indexPixel)
    {
        return pPixels + indexPixel * PixelSize;
    }

    static void replicatePixel(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint8_t* pEnd = pPixelDest + (count * PixelSize);
        while (pPixelDest < pEnd)
        {
            for (uint8_t iElement = 0; iElement < PixelSize; iElement++)
            {
                *pPixelDest++ = pPixelSrc[iElement];
            }
        }
    }

    static void movePixelsInc(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint8_t* pEnd = pPixelDest + (count * PixelSize);
        while (pPixelDest < pEnd)
        {
            *pPixelDest++ = *pPixelSrc++;
        }
    }

    static void movePixelsInc_P(uint8_t* pPixelDest, PGM_VOID_P pPixelSrc, uint16_t count)
    {
        uint8_t* pEnd = pPixelDest + (count * PixelSize);
        const uint8_t* pSrc = reinterpret_cast<const uint8_t*>(pPixelSrc);
        while (pPixelDest < pEnd)
        {
            *pPixelDest++ = pgm_read_byte(pSrc++);
        }
    }

    static void movePixelsDec(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint8_t* pDestBack = pPixelDest + (count * PixelSize);
        const uint8_t* pSrcBack = pPixelSrc + (count * PixelSize);
        while (pDestBack > pPixelDest)
        {
            *--pDestBack = *--pSrcBack;
        }
    }

    typedef RgbColor ColorObject;
};

class Neo4ByteElements
{
public:
    static const size_t PixelSize = 4;

    static uint8_t* getPixelAddress(uint8_t* pPixels, uint16_t indexPixel) 
    {
        return pPixels + indexPixel * PixelSize;
    }
    static const uint8_t* getPixelAddress(const uint8_t* pPixels, uint16_t indexPixel)
    {
        return pPixels + indexPixel * PixelSize;
    }

    static void replicatePixel(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint32_t* pDest = reinterpret_cast<uint32_t*>(pPixelDest);
        const uint32_t* pSrc = reinterpret_cast<const uint32_t*>(pPixelSrc);

        uint32_t* pEnd = pDest + count;
        while (pDest < pEnd)
        {
            *pDest++ = *pSrc;
        }
    }

    static void movePixelsInc(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint32_t* pDest = reinterpret_cast<uint32_t*>(pPixelDest);
        const uint32_t* pSrc = reinterpret_cast<const uint32_t*>(pPixelSrc);
        uint32_t* pEnd = pDest + count;
        while (pDest < pEnd)
        {
            *pDest++ = *pSrc++;
        }
    }

    static void movePixelsInc_P(uint8_t* pPixelDest, PGM_VOID_P pPixelSrc, uint16_t count)
    {
        uint32_t* pDest = reinterpret_cast<uint32_t*>(pPixelDest);
        const uint32_t* pSrc = reinterpret_cast<const uint32_t*>(pPixelSrc);
        uint32_t* pEnd = pDest + count;
        while (pDest < pEnd)
        {
            *pDest++ = pgm_read_dword(pSrc++); 
        }
    }

    static void movePixelsDec(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint32_t* pDest = reinterpret_cast<uint32_t*>(pPixelDest);
        const uint32_t* pSrc = reinterpret_cast<const uint32_t*>(pPixelSrc);
        uint32_t* pDestBack = pDest + count;
        const uint32_t* pSrcBack = pSrc + count;
        while (pDestBack > pDest)
        {
            *--pDestBack = *--pSrcBack;
        }
    }

    typedef RgbwColor ColorObject;
};

class Neo6ByteElements
{
public:
    static const size_t PixelSize = 6;

    static uint8_t* getPixelAddress(uint8_t* pPixels, uint16_t indexPixel)
    {
        return pPixels + indexPixel * PixelSize;
    }
    static const uint8_t* getPixelAddress(const uint8_t* pPixels, uint16_t indexPixel)
    {
        return pPixels + indexPixel * PixelSize;
    }

    static void replicatePixel(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint16_t* pDest = reinterpret_cast<uint16_t*>(pPixelDest);
        const uint16_t* pSrc = reinterpret_cast<const uint16_t*>(pPixelSrc);

        uint16_t* pEnd = pDest + (count * PixelSize / 2);
        while (pDest < pEnd)
        {
            *pDest++ = *pSrc;
        }
    }

    static void movePixelsInc(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint16_t* pDest = reinterpret_cast<uint16_t*>(pPixelDest);
        const uint16_t* pSrc = reinterpret_cast<const uint16_t*>(pPixelSrc);
        uint16_t* pEnd = pDest + (count * PixelSize / 2);
        while (pDest < pEnd)
        {
            *pDest++ = *pSrc++;
        }
    }

    static void movePixelsInc_P(uint8_t* pPixelDest, PGM_VOID_P pPixelSrc, uint16_t count)
    {
        uint16_t* pDest = reinterpret_cast<uint16_t*>(pPixelDest);
        const uint16_t* pSrc = reinterpret_cast<const uint16_t*>(pPixelSrc);
        uint16_t* pEnd = pDest + (count * PixelSize / 2);
        while (pDest < pEnd)
        {
            *pDest++ = pgm_read_word(pSrc++);
        }
    }

    static void movePixelsDec(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint16_t* pDest = reinterpret_cast<uint16_t*>(pPixelDest);
        const uint16_t* pSrc = reinterpret_cast<const uint16_t*>(pPixelSrc);
        uint16_t* pDestBack = pDest + (count * PixelSize / 2);
        const uint16_t* pSrcBack = pSrc + (count * PixelSize / 2);
        while (pDestBack > pDest)
        {
            *--pDestBack = *--pSrcBack;
        }
    }

    typedef Rgb48Color ColorObject;
};

class Neo8ByteElements
{
public:
    static const size_t PixelSize = 8;

    static uint8_t* getPixelAddress(uint8_t* pPixels, uint16_t indexPixel)
    {
        return pPixels + indexPixel * PixelSize;
    }
    static const uint8_t* getPixelAddress(const uint8_t* pPixels, uint16_t indexPixel)
    {
        return pPixels + indexPixel * PixelSize;
    }

    static void replicatePixel(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint32_t* pDest = reinterpret_cast<uint32_t*>(pPixelDest);
        const uint32_t* pSrc = reinterpret_cast<const uint32_t*>(pPixelSrc);

        uint32_t* pEnd = pDest + (count * PixelSize);
        while (pDest < pEnd)
        {
            *pDest++ = *pSrc;
        }
    }

    static void movePixelsInc(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint32_t* pDest = reinterpret_cast<uint32_t*>(pPixelDest);
        const uint32_t* pSrc = reinterpret_cast<const uint32_t*>(pPixelSrc);
        uint32_t* pEnd = pDest + (count * PixelSize);
        while (pDest < pEnd)
        {
            *pDest++ = *pSrc++;
        }
    }

    static void movePixelsInc_P(uint8_t* pPixelDest, PGM_VOID_P pPixelSrc, uint16_t count)
    {
        uint32_t* pDest = reinterpret_cast<uint32_t*>(pPixelDest);
        const uint32_t* pSrc = reinterpret_cast<const uint32_t*>(pPixelSrc);
        uint32_t* pEnd = pDest + (count * PixelSize);
        while (pDest < pEnd)
        {
            *pDest++ = pgm_read_dword(pSrc++);
        }
    }

    static void movePixelsDec(uint8_t* pPixelDest, const uint8_t* pPixelSrc, uint16_t count)
    {
        uint32_t* pDest = reinterpret_cast<uint32_t*>(pPixelDest);
        const uint32_t* pSrc = reinterpret_cast<const uint32_t*>(pPixelSrc);
        uint32_t* pDestBack = pDest + (count * PixelSize);
        const uint32_t* pSrcBack = pSrc + (count * PixelSize);
        while (pDestBack > pDest)
        {
            *--pDestBack = *--pSrcBack;
        }
    }

    typedef Rgbw64Color ColorObject;
};

class Neo3ByteElementsNoSettings : public Neo3ByteElements
{
public:
    typedef NeoNoSettings SettingsObject;
    static const size_t SettingsSize = 0;

    static void applySettings(uint8_t*, const SettingsObject&)
    {
    }

    static uint8_t* pixels(uint8_t* pData)
    {
        return pData;
    }

    static const uint8_t* pixels(const uint8_t* pData)
    {
        return pData;
    }
};

class Neo4ByteElementsNoSettings : public Neo4ByteElements
{
public:
    typedef NeoNoSettings SettingsObject;
    static const size_t SettingsSize = 0;

    static void applySettings(uint8_t*, const SettingsObject&)
    {
    }

    static uint8_t* pixels(uint8_t* pData)
    {
        return pData;
    }

    static const uint8_t* pixels(const uint8_t* pData)
    {
        return pData;
    }
};

class Neo6ByteElementsNoSettings : public Neo6ByteElements
{
public:
    typedef NeoNoSettings SettingsObject;
    static const size_t SettingsSize = 0;

    static void applySettings(uint8_t*, const SettingsObject&)
    {
    }

    static uint8_t* pixels(uint8_t* pData)
    {
        return pData;
    }

    static const uint8_t* pixels(const uint8_t* pData)
    {
        return pData;
    }
};

class Neo8ByteElementsNoSettings : public Neo8ByteElements
{
public:
    typedef NeoNoSettings SettingsObject;
    static const size_t SettingsSize = 0;

    static void applySettings(uint8_t*, const SettingsObject&)
    {
    }

    static uint8_t* pixels(uint8_t* pData)
    {
        return pData;
    }

    static const uint8_t* pixels(const uint8_t* pData)
    {
        return pData;
    }
};

class NeoGrbFeature : public Neo3ByteElementsNoSettings
{
public:
    static void applyPixelColor(uint8_t* pPixels, uint16_t indexPixel, ColorObject color)
    {
        uint8_t* p = getPixelAddress(pPixels, indexPixel);

        *p++ = color.G;
        *p++ = color.R;
        *p = color.B;
    }

    static ColorObject retrievePixelColor(const uint8_t* pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(pPixels, indexPixel);

        color.G = *p++;
        color.R = *p++;
        color.B = *p;

        return color;
    }
    
    static ColorObject retrievePixelColor_P(PGM_VOID_P pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(reinterpret_cast<const uint8_t*>(pPixels), indexPixel);

        color.G = pgm_read_byte(p++);
        color.R = pgm_read_byte(p++);
        color.B = pgm_read_byte(p);

        return color;
    }
    
};

class NeoGrbwFeature : public Neo4ByteElementsNoSettings
{
public:
    static void applyPixelColor(uint8_t* pPixels, uint16_t indexPixel, ColorObject color)
    {
        uint8_t* p = getPixelAddress(pPixels, indexPixel);

        *p++ = color.G;
        *p++ = color.R;
        *p++ = color.B;
        *p = color.W;
    }

    static ColorObject retrievePixelColor(const uint8_t* pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(pPixels, indexPixel);

        color.G = *p++;
        color.R = *p++;
        color.B = *p++;
        color.W = *p;


        return color;
    }
    
    static ColorObject retrievePixelColor_P(PGM_VOID_P pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(reinterpret_cast<const uint8_t*>(pPixels), indexPixel);

        color.G = pgm_read_byte(p++);
        color.R = pgm_read_byte(p++);
        color.B = pgm_read_byte(p++);
        color.W = pgm_read_byte(p);

        return color;
    }
    
};

class NeoRgbwFeature : public Neo4ByteElementsNoSettings
{
public:
    static void applyPixelColor(uint8_t* pPixels, uint16_t indexPixel, ColorObject color)
    {
        uint8_t* p = getPixelAddress(pPixels, indexPixel);

        *p++ = color.R;
        *p++ = color.G;
        *p++ = color.B;
        *p = color.W;
    }

    static ColorObject retrievePixelColor(const uint8_t* pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(pPixels, indexPixel);

        color.R = *p++;
        color.G = *p++;
        color.B = *p++;
        color.W = *p;

        return color;
    }
    
    static ColorObject retrievePixelColor_P(PGM_VOID_P pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(reinterpret_cast<const uint8_t*>(pPixels), indexPixel);

        color.R = pgm_read_byte(p++);
        color.G = pgm_read_byte(p++);
        color.B = pgm_read_byte(p++);
        color.W = pgm_read_byte(p);

        return color;
    }
    
};

class NeoRgbFeature : public Neo3ByteElementsNoSettings
{
public:
    static void applyPixelColor(uint8_t* pPixels, uint16_t indexPixel, ColorObject color)
    {
        uint8_t* p = getPixelAddress(pPixels, indexPixel);

        *p++ = color.R;
        *p++ = color.G;
        *p = color.B;
    }

    static ColorObject retrievePixelColor(const uint8_t* pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(pPixels, indexPixel);

        color.R = *p++;
        color.G = *p++;
        color.B = *p;

        return color;
    }
    
    static ColorObject retrievePixelColor_P(PGM_VOID_P pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(reinterpret_cast<const uint8_t*>(pPixels), indexPixel);

        color.R = pgm_read_byte(p++);
        color.G = pgm_read_byte(p++);
        color.B = pgm_read_byte(p);

        return color;
    }
    
};

class NeoBrgFeature : public Neo3ByteElementsNoSettings
{
public:
    static void applyPixelColor(uint8_t* pPixels, uint16_t indexPixel, ColorObject color)
    {
        uint8_t* p = getPixelAddress(pPixels, indexPixel);

        *p++ = color.B;
        *p++ = color.R;
        *p = color.G;
    }

    static ColorObject retrievePixelColor(const uint8_t* pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(pPixels, indexPixel);

        color.B = *p++;
        color.R = *p++;
        color.G = *p;

        return color;
    }
    
    static ColorObject retrievePixelColor_P(PGM_VOID_P pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(reinterpret_cast<const uint8_t*>(pPixels), indexPixel);

        color.B = pgm_read_byte(p++);
        color.R = pgm_read_byte(p++);
        color.G = pgm_read_byte(p);

        return color;
    }
    
};

class NeoRbgFeature : public Neo3ByteElementsNoSettings
{
public:
    static void applyPixelColor(uint8_t* pPixels, uint16_t indexPixel, ColorObject color)
    {
        uint8_t* p = getPixelAddress(pPixels, indexPixel);

        *p++ = color.R;
        *p++ = color.B;
        *p = color.G;
    }

    static ColorObject retrievePixelColor(const uint8_t* pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(pPixels, indexPixel);

        color.R = *p++;
        color.B = *p++;
        color.G = *p;

        return color;
    }

    
    static ColorObject retrievePixelColor_P(PGM_VOID_P pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(reinterpret_cast<const uint8_t*>(pPixels), indexPixel);

        color.R = pgm_read_byte(p++);
        color.B = pgm_read_byte(p++);
        color.G = pgm_read_byte(p);

        return color;
    }
    
};

class NeoBgrFeature : public Neo3ByteElementsNoSettings
{
public:
    static void applyPixelColor(uint8_t* pPixels, uint16_t indexPixel, ColorObject color)
    {
        uint8_t* p = getPixelAddress(pPixels, indexPixel);

        *p++ = color.B;
        *p++ = color.G;
        *p = color.R;
    }

    static ColorObject retrievePixelColor(const uint8_t* pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(pPixels, indexPixel);

        color.B = *p++;
        color.G = *p++;
        color.R = *p;

        return color;
    }

    
    static ColorObject retrievePixelColor_P(PGM_VOID_P pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint8_t* p = getPixelAddress(reinterpret_cast<const uint8_t*>(pPixels), indexPixel);

        color.B = pgm_read_byte(p++);
        color.G = pgm_read_byte(p++);
        color.R = pgm_read_byte(p);

        return color;
    }
    
};

class NeoRgbw64Feature : public Neo8ByteElementsNoSettings
{
public:
    static void applyPixelColor(uint8_t* pPixels, uint16_t indexPixel, ColorObject color)
    {
        uint16_t* p = reinterpret_cast<uint16_t *>(getPixelAddress(pPixels, indexPixel));

        *p++ = color.R;
        *p++ = color.G;
        *p++ = color.B;
        *p = color.W;
    }

    static ColorObject retrievePixelColor(const uint8_t* pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint16_t* p = reinterpret_cast<const uint16_t*>(getPixelAddress(pPixels, indexPixel));

        color.R = *p++;
        color.G = *p++;
        color.B = *p++;
        color.W = *p;

        return color;
    }

    static ColorObject retrievePixelColor_P(PGM_VOID_P pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint16_t* p = reinterpret_cast<const uint16_t*>(getPixelAddress(reinterpret_cast<const uint8_t*>(pPixels), indexPixel));

        color.R = pgm_read_word(p++);
        color.G = pgm_read_word(p++);
        color.B = pgm_read_word(p++);
        color.W = pgm_read_word(p);

        return color;
    }
};

class NeoRgb48Feature : public Neo6ByteElementsNoSettings
{
public:
    static void applyPixelColor(uint8_t* pPixels, uint16_t indexPixel, ColorObject color)
    {
        uint16_t* p = reinterpret_cast<uint16_t*>(getPixelAddress(pPixels, indexPixel));

        *p++ = color.R;
        *p++ = color.G;
        *p = color.B;
    }

    static ColorObject retrievePixelColor(const uint8_t* pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint16_t* p = reinterpret_cast<const uint16_t*>(getPixelAddress(pPixels, indexPixel));

        color.R = *p++;
        color.G = *p++;
        color.B = *p;

        return color;
    }

    static ColorObject retrievePixelColor_P(PGM_VOID_P pPixels, uint16_t indexPixel)
    {
        ColorObject color;
        const uint16_t* p = reinterpret_cast<const uint16_t*>(getPixelAddress(reinterpret_cast<const uint8_t*>(pPixels), indexPixel));

        color.R = pgm_read_word(p++);
        color.G = pgm_read_word(p++);
        color.B = pgm_read_word(p);

        return color;
    }
};

typedef NeoRgb48Feature NeoRgbUcs8903Feature;
typedef NeoRgbw64Feature NeoRgbwUcs8904Feature;