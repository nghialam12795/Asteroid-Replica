#ifndef ASTEROID_ENTITY_H_
#define ASTEROID_ENTITY_H_

class Entity {
 public:
  Entity();
  ~Entity();

  static Entity ALL[];

 private:
  float _cx;
  float _cy;
  float _xr;
  float _yr;
};

#endif //ASTEROID_ENTITY_H_
