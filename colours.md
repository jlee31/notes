# Colour Spaces and Colour Theory

## How Does RGB Work?

- Our eyes have **three main receptors (cones):**
  1. One for longer wavelengths (**red**)
  2. One for medium wavelengths (**green**)
  3. One for shorter wavelengths (**blue**)

- Computers use **RGB lights** in the same fashion, illuminating these colours accordingly.

- Other animals have different cones in their eyes (some can't see red).  
  For example, certain insects have **12 receptors**!

- **RGB is additive:**  
  Adding red, green, and blue lights creates **brighter colours**.

- **Subtractive colours** (like inks and paints) work oppositely:  
  They mix to create **darker colours** by absorbing light.

---

## Complementary Colours

- Colours that are opposite each other on the colour wheel.

**Examples:**
- Santa and Christmas tree → **Red and Green**  
- Fanta sign → **Blue and Orange**  
- Lotus flower → **Yellow and Purple**

---

## Screens and Pixels

- Screens are made up of **pixels**, each containing small RGB lights.  
- **Resolution:** Number of pixels on a screen.  
- **Pixel density:** More pixels in the same amount of physical space = sharper images.

- Images store data as **tuples of RGB values**.

---

## Why is RGB up to 255?

- Each RGB channel uses **8 bits**.  
- Binary `11111111` = **255** in decimal.  
- So, each channel ranges from 0 to 255.

---

## Changing Colours in Photos

- To alter colours, you can apply **functions to map RGB values** to new RGB values.


# Additional from Chat:
# Colour Theory for Computer Vision

## 1. Colour Spaces and Models
- **RGB:** Additive, used for screens and cameras.
- **HSV / HSL:** Separates Hue (colour) from Saturation (purity) and Value/Lightness (brightness). Useful for segmentation.
- **CMYK:** Subtractive, mainly for printing.
- **Lab (CIELAB):** Human vision based; separates luminance (L) and chromaticity (a, b). Good for colour comparison.
- **YUV / YCbCr:** Separates luminance from chrominance. Used in video compression.

## 2. Colour Space Conversion
- Essential to convert between spaces (e.g., RGB → HSV, RGB → Lab) for feature extraction and processing.

## 3. Perception-Based Concepts
- **Hue, Saturation, Brightness:** Reflect human colour perception better than raw RGB.
- **Complementary Colours:** Used for contrast enhancement.
- **Colour Constancy:** Adjusting for lighting changes (e.g., white balancing).

## 4. Colour Quantization
- Reducing colour palette size for compression and segmentation.

## 5. Colour Histograms & Features
- Represent colour distributions; used in object recognition and image retrieval.

## 6. Illumination and Shadows
- Handle lighting variations to improve robustness.

## Bonus: Human Vision vs Sensors
- Different animals perceive colours differently.
- Multispectral/hyperspectral imaging captures beyond RGB.
