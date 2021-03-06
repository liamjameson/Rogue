#ifndef OBJECT_H
# define OBJECT_H

# include <string>
# include <stdint.h>
# include <vector>
# include <cstdlib>

# include "descriptions.h"
# include "dims.h"

class object {
 private:
  const std::string &name;
  const std::string &description;
  object_type_t type;
  uint32_t color;
  const dice &damage;
  int32_t hit, dodge, defence, weight, speed, attribute, value;
  bool seen;
  object *next;
  object_description &od;
 public:
 pair_t position;
  object(object_description &o, pair_t p, object *next);
  //object(const object&);
  ~object();
  inline int32_t get_damage_base() const
  {
    return damage.get_base();
  }
  inline int32_t get_damage_number() const
  {
    return damage.get_number();
  }
  inline int32_t get_damage_sides() const
  {
    return damage.get_sides();
  }
  char get_symbol();
  uint32_t get_color();
  const char *get_name();
  const char *get_description();
  int32_t get_speed();
  int32_t roll_dice();
  int32_t get_type();
  bool have_seen() { return seen; }
  void has_been_seen() { seen = true; }
  int16_t *get_position() { return position; }
};

void gen_objects(dungeon_t *d);
char object_get_symbol(object *o);
void destroy_objects(dungeon_t *d);
void set_object_position(object *o, pair_t *p);

#endif
