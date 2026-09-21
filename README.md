# CPU Rasterizer

A software rasterizer built from scratch in C++, without any graphics APIs or libraries.
Renders output as PPM image files.

## What it does
- Framebuffer: pixel buffer in memory with PPM export
- Line drawing: Bresenham's line algorithm

## Building
```bash
g++ main.cpp -o rasterizer
./rasterizer
```

## Roadmap
- [ ] Fix line drawing for all slopes (octant handling)
- [ ] Triangle rasterization
- [ ] Z-buffer / depth testing
- [ ] Texture mapping
- [ ] OBJ file loading
- [ ] Lighting (Phong)
- [ ] SIMD optimization