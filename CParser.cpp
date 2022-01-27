#include "CParser.h"

/*Cette m�thode renvoie un std::string sans espace avant et apr�s du string pass� en param�tre.
@chaine std::string est le std::string � convertir
*/
std::string CParser::enleverEspaceChaine(std::string chaine)
{
	int espaceDebut = 0;
	int espacefin = 0;

	for (unsigned i = 0; i<chaine.length(); ++i)
	{

		if (chaine.at(0) == ' ' || chaine.at(0) == '\t')
		{
			chaine.erase(0, 1);
		}
		if (chaine.at(chaine.size() - 1) == ' ' || chaine.at(0) == '\t')
		{
			chaine.erase(chaine.size() - 1, 1);
		}

	}

	return chaine;
}



/*Cette m�thode permet de stocker les ligne d'un fichier dans un std::vector<std::string>.
@p_nomFichier std::string est le nom du fichier pour initialiser le vecteur
*/
void CParser::lireFichier(std::string p_nomFichier)
{
	std::string line;
	std::ifstream myFile(p_nomFichier);
	std::vector<std::string> l_ligneFichier;
	if (myFile.is_open())
	{
		while (getline(myFile, line))
			l_ligneFichier.push_back(enleverEspaceChaine(line));
		myFile.close();
		setm_ligneFichier(l_ligneFichier);
	}
	else
		std::cout << "Impossible d�ouvrir le fichier \n";
}

/*Cette m�thode permet d'afficher sur la console les ligne du fichier cibl� en param�tre
@p_nomFichier std::string est le nom du fichier pour initialiser le vecteur
*/
void CParser::afficherContenufichier(std::string p_nomFichier)
{
	lireFichier(p_nomFichier);
	for (unsigned i = 0; i<getm_ligneFichier().size(); i++)
		std::cout << getm_ligneFichier()[i] << std::endl;
}



/*Cette m�thode est un getter()
Elle retourne std::vector<std::string> du membre proteg� m_ligneFichier de la classe CParser
*/
std::vector<std::string> CParser::getm_ligneFichier()
{
	return m_ligneFichier;
}


/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_ligneFichier de la classe CParser
avec le param�tre de cette m�thode
@p_ligneFichier std::vector<std::string> permetant d'innitialiser le membre m_ligneFichier
*/
void CParser::setm_ligneFichier(std::vector<std::string> p_ligneFichier)
{
	m_ligneFichier = p_ligneFichier;
}


CParser::CParser()
{

}

CParser::~CParser()
{

}
