#ifndef MAP_H
#define MAP_H
class Map {
 public:
  Map(int N);
  Map(const Map& map);
  void showMap();
  int findRoutea();
  int findRouteb();
  int findRoutec();
  void showRoutea();
  void showRouteb();

  int N;
  int** arr;
  ~Map();
};
#endif
