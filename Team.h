#pragma once
#include "Sticker.h"
#include<string>
class Team {
 Sticker players[11];
 size_t size;
 char* mngName;
 std::string stadium;

 void free();
 void copyFrom(const Team& other);
 void moveFrom(Team&& other);
public:
  Team();
  Team(const Sticker* players,size_t size,const char* mngName,const std::string& stadium);
  Team(const Team& other);
  Team& operator=(const Team& other);
  Team(Team&& other) noexcept;
  Team& operator=(Team&& other) noexcept;
  ~Team();
  double avrgRating() const;
  friend std::ostream& operator<<(std::ostream& os,const Team& team);

};

std::ostream& operator<<(std::ostream& os,const Team& team);

inline std::ostream & operator<<(std::ostream &os, const Team &team) {
    os<<"Manager:"<<team.mngName<<" Stadium:"<<team.stadium<<std::endl;
    for (int i=0; i<team.size; ++i) {
        os<<team.players[i];
    }
    return os;
}
