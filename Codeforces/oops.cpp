#include <iostream>
#include <algorithm>

struct Point
{
  int x, y, z;
};

struct Cuboid
{
  Point p1, p2;

  Cuboid(int a, int b, int c, int d, int e, int f)
  {
    p1 = {std::min(a, d), std::min(b, e), std::min(c, f)};
    p2 = {std::max(a, d), std::max(b, e), std::max(c, f)};
  }
};

bool hasPositiveVolumeIntersection(const Cuboid &c1, const Cuboid &c2)
{
  return (c1.p1.x < c2.p2.x && c1.p2.x > c2.p1.x) &&
         (c1.p1.y < c2.p2.y && c1.p2.y > c2.p1.y) &&
         (c1.p1.z < c2.p2.z && c1.p2.z > c2.p1.z);
}

int main()
{
  int a, b, c, d, e, f;
  int g, h, i, j, k, l;

  std::cout << "Enter coordinates for the first cuboid (a, b, c, d, e, f): ";
  std::cin >> a >> b >> c >> d >> e >> f;
  Cuboid cuboid1(a, b, c, d, e, f);

  std::cout << "Enter coordinates for the second cuboid (g, h, i, j, k, l): ";
  std::cin >> g >> h >> i >> j >> k >> l;
  Cuboid cuboid2(g, h, i, j, k, l);

  if (hasPositiveVolumeIntersection(cuboid1, cuboid2))
  {
    std::cout << "The cuboids intersect with positive volume." << std::endl;
  }
  else
  {
    std::cout << "The cuboids do not intersect with positive volume." << std::endl;
  }

  return 0;
}