#include "../../include/Common/MusicPlayer.h"

namespace testM {
void testM() {
    MusicPlayer m;
    Song s = {"h", "bob", "--MAGICALBOB--", 489};
    Song b = {"jilly", "indigo", "Fun Jilly Land Art **:)**", 302};
    std::string hors_art = R"(              .     :     .
            .  :    |    :  .
             .  |   |   |  ,
              \  |     |  /
          .     ,-'"""`-.     .
            "- /  __ __  \ -"
              |==|  I  |==|
        - --- | _`--^--'_ | --- -
              |'`.     ,'`|
            _- \  "---"  / -_
          .     `-.___,-'     .
              /  |     |  \
            .'  |   |   |  `.
               :    |    :
              .     :     .)";

    Song q = {"House of the Rising Sun", "The Animals", hors_art, 269};
    m.addSong(s);
    m.addSong(b);
    m.addSong(q);
    m.display();
    m.buildPlaylist();
}
}  // namespace testM