/*!
  \file   macros.hpp
  \brief  Macros usadas para el menu.
  \author Fco. Javier Clavero Alvarez.
  \date   23/03/2015
*/

#ifndef MACROS_HPP
#define MACROS_HPP

#define LUGAR(x,y)   printf("\033[%d;%dH",x,y) //!< LUGAR
#define BORRAR       printf("\33[2J")   //!< BORRAR
#define PARPADEO     printf("%c[5m",27) //!< PARPADEO
#define APAGA        printf("%c[0m",27) //!< APAGA
#define INVERSO      printf("%c[7m",27) //!< INVERSO
#define SUBRAYADO    printf("%c[4m",27) //!< SUBRAYADO
#define INTENSIDAD   printf("%c[1m",27) //!< INTENSIDAD

#define RESET printf("\e[m") //!< RESET

#define GREEN printf("\e[32m")   //!< GREEN
#define RED printf("\e[31m")     //!< RED
#define YELLOW printf("\e[33m")  //!< YELLOW
#define BLUE printf("\e[34m")    //!< BLUE
#define WHITE printf("\e[37m")   //!< WHITE
#define MAGENTA printf("\e[35m") //!< MAGENTA
#define BLACK printf("\e[30m")   //!<BLACK

#define ONGREEN printf("\e[42m")   //!< ONGREEN
#define ONRED printf("\e[41m")     //!< ONRED
#define ONYELLOW printf("\e[43m")  //!< ONYELLOW
#define ONBLUE printf("\e[44m")    //!< ONBLUE
#define ONWHITE printf("\e[47m")   //!< ONWHITE
#define ONMAGENTA printf("\e[45m") //!< ONMAGENTA
#define ONBLACK printf("\e[40m")   //!< ONBLACK


#endif
