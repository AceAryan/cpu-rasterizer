# CPU Rasterizer

A software rasterizer built from scratch in C++, without any graphics APIs or libraries.
Renders output as PPM image files.

## What it does
- Framebuffer: pixel buffer in memory with PPM export
- Line drawing: Bresenham's line algorithm (all 8 octants)
- Triangle outline: 3-point wireframe via drawTriangle

## Building
```bash
g++ main.cpp -o rasterizer
./rasterizer
```

## Roadmap
- [x] Fix line drawing for all slopes (octant handling)
- [x] Triangle outline
- [ ] Filled triangle (barycentric coordinates)
- [ ] Z-buffer / depth testing
- [ ] OBJ file loading
- [ ] Lighting (Phong)
- [ ] SIMD optimization