
#ifndef SVGFILE_H_INCLUDED
#define SVGFILE_H_INCLUDED
#include <string>
#include <fstream>
#include <set>

///la couleur du trac� sur le output sera noir
constexpr char defcol[] = "black";

///classe associ�e � l'affichage des graphes
class Svgfile
{
public:
    Svgfile(std::string _filename = "output.svg", int _width=2000, int _height=2000); //creation de la file svg
    ~Svgfile();
//pour chaque forme on a ses coord, sa couleur de remplissage, sa couleur de bordure et son �paisseur
    void addDisk(double x, double y, double r, std::string color=defcol); //fct pour crer disque
    void addCircle(double x, double y, double r, double ep, std::string color=defcol); //fct pour cr�e cercle
    void addTriangle(double x1, double y1, double x2, double y2,
                     double x3, double y3, std::string colorFill,
                     double thickness, std::string colorStroke);//fct pour creer rectangle
    void addTriangle(double x1, double y1, double x2, double y2,
                     double x3, double y3, std::string colorFill=defcol); //rectangle avec couleur de d�faut indiqu�e au d�but
    void addRectangle(double x1, double y1, double x2, double y2,
                      double x3, double y3,double x4, double y4,
                      std::string colorFill,double thickness, std::string colorStroke); //ajout de r�ctangle

    void addLine(double x1, double y1, double x2, double y2, std::string color=defcol); //ajout ligne
    void addLines(double x1, double y1, double x2, double y2, std::string color=defcol); //ajout lignes
    void addCross(double x, double y, double span, std::string color=defcol); //ajout croix

    void addText(double x, double y, std::string text, std::string color=defcol); //ajout texte
    void addText(double x, double y, double val, std::string color=defcol);

    void addGrid(double span=100.0, bool numbering=true, std::string color="lightgrey"); //grille de fond

    static std::string makeRGB(int r, int g, int b);

    /// Type non copiable
    Svgfile(const Svgfile&) = delete;
    Svgfile& operator=(const Svgfile&) = delete;

    static bool s_verbose; //couleur

private:
    std::string m_filename; //nom de la file
    std::ofstream m_ostrm;
    int m_width; //taille
    int m_height; //taille

    // Pour �viter les ouverture multiples
    static std::set<std::string> s_openfiles;
};

#endif // SVGFILE_H_INCLUDED
