#include <fstream>
#include <agg_pixfmt_rgb.h>
#include <agg_renderer_base.h>
#include <agg_renderer_primitives.h>

void
write_ppm(const unsigned char *buf, unsigned int width,
          unsigned int height, const char *filename)
{
    std::ofstream f(filename, std::ios_base::binary);

    f << "P6 " << width << " " << height << " 255 ";
    f.write((char *)buf, width * height * 3);
    f.close();
}


int main()
{
    const unsigned int width = 300;
    const unsigned int height = 300;
    const unsigned int depth = 3;
    unsigned char *buf = new unsigned char[width * height * depth];

    agg::rendering_buffer rbuf(buf, width, height, width * depth);
    agg::pixfmt_rgb24 pixf(rbuf);
    agg::renderer_base<agg::pixfmt_rgb24> ren_base(pixf);

    ren_base.clear(agg::rgba8(255, 250, 230));

    agg::renderer_primitives<agg::renderer_base<agg::pixfmt_rgb24> >  ren_prim(ren_base);
    ren_prim.line_color(agg::rgba8(0, 0, 0));
    ren_prim.fill_color(agg::rgba8(255, 0, 0));

    ren_prim.rectangle(10, 20, 100, 150);
    ren_prim.solid_rectangle(30, 40, 90, 140);

    ren_prim.line_color(agg::rgba8(0, 0, 255));
    ren_prim.line(200 * 256, 200 * 256, 290 * 256, 290 * 256);
    ren_prim.move_to(200 * 256, 0);
    ren_prim.line_to(210 * 256, 120 * 256);
    ren_prim.line_to(240 * 256, 70 * 256);

    write_ppm(buf, width, height, "result.ppm");
    delete[] buf;
    return 0;
}
