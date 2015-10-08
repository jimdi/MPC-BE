// CDPI class is based on an example from the article "Writing DPI-Aware Win32 Applications".
// http://download.microsoft.com/download/1/f/e/1fe476f5-2b7a-4af1-a0ed-768454a0b5b1/Writing%20DPI%20Aware%20Applications.pdf

#pragma once

// Definition: relative pixel = 1 pixel at 96 DPI and scaled based on actual DPI.
class CDPI
{
public:
    CDPI() : _dpiX(96), _dpiY(96) { _Init(); }

    // Get screen DPI.
    int GetDPIX() { return _dpiX; }
    int GetDPIY() { return _dpiY; }

    // Convert between raw pixels and relative pixels.
    int ScaleX(int x) { return MulDiv(x, _dpiX, 96); }
    int ScaleY(int y) { return MulDiv(y, _dpiY, 96); }
    int UnscaleX(int x) { return MulDiv(x, 96, _dpiX); }
    int UnscaleY(int y) { return MulDiv(y, 96, _dpiY); }

    // Scale rectangle from raw pixels to relative pixels.
    void ScaleRect(__inout RECT *pRect)
    {
        pRect->left = ScaleX(pRect->left);
        pRect->right = ScaleX(pRect->right);
        pRect->top = ScaleY(pRect->top);
        pRect->bottom = ScaleY(pRect->bottom);
    }

    // Convert a point size (1/72 of an inch) to raw pixels.
    int PointsToPixels(int pt) { return MulDiv(pt, _dpiY, 72); }

private:
    void _Init()
    {
        HDC hdc = GetDC(NULL);
        if (hdc)
        {
            _dpiX = GetDeviceCaps(hdc, LOGPIXELSX);
            _dpiY = GetDeviceCaps(hdc, LOGPIXELSY);
            ReleaseDC(NULL, hdc);
        }
    }

private:
    int _dpiX;
    int _dpiY;
};
