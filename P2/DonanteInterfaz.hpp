#ifndef DONANTEINTERFAZ_HPP
#define DONANTEINTERFAZ_HPP
#include <string>
namespace ed{
	class DonanteInterfaz {
		public:
			virtual void setNombre(std::string const &n)=0;
			virtual void setApellidos(std::string const &a)=0;
			virtual bool setGrupo(std::string const &g)=0;
			virtual bool setFRH(std::string const &f)=0;
			virtual std::string getNombre() const=0;
			virtual std::string getApellidos() const=0;
			virtual std::string getGrupo() const=0;
			virtual std::string getFRH() const=0;
	};
}
#endif
