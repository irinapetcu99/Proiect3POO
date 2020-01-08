#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Farmacie
{
    protected:
        string denumire;
        int nr_ang;
        double *profit;

    public:
        Farmacie()
            {
                denumire = "";
                nr_ang = 0;
                profit = new double[12];
            }

        Farmacie(string denumire, int nr_ang, const double* &profit)
        {
            this -> denumire = denumire;
            this -> nr_ang = nr_ang;
            profit = new double[12];
            for(int i = 0; i < 12; i++)
                this -> profit[i] = profit[i];
        }

        Farmacie(const Farmacie &ob)
        {
            denumire = ob.denumire;
            nr_ang = ob.nr_ang;
            profit = new double[12];
            for(int i = 0; i < 12; i++)
                profit[i] = ob.profit[i];

        }

        virtual ~Farmacie()
        {
            denumire = "";
            nr_ang = 0;
            delete profit;
        }

        const Farmacie& operator =(const Farmacie &ob)
        {
            if(this == &ob)
                return *this;
            delete profit;
            profit = new double[12];
            denumire = ob.denumire;
            nr_ang = ob.nr_ang;
            for(int i = 0; i < 12; i++)
                profit[i] = ob.profit[i];
            return *this;
        }

        friend istream& operator >>(istream &in, Farmacie &ob);

        virtual void afisare()
        {
            cout << "Denumirea:" << denumire << endl;
            cout << "Numarul de angajati:" << nr_ang << endl;
            cout << "Profitul pe toate lunile:" << endl;
            for(int i = 0; i < 12; i++)
            {
                if(i == 0)
                cout << "Luna ianuarie:";
                if(i == 1)
                cout << "Luna februarie:";
                if(i == 2)
                cout << "Luna martie:";
                if(i == 3)
                cout << "Luna aprilie:";
                if(i == 4)
                cout << "Luna mai:";
                if(i == 5)
                cout << "Luna iunie:";
                if(i == 6)
                cout << "Luna iulie:";
                if(i == 7)
                cout << "Luna august:";
                if(i == 8)
                cout << "Luna septembrie:";
                if(i == 9)
                cout << "Luna octombrie:";
                if(i == 10)
                cout << "Luna noiembrie:";
                if(i == 11)
                cout << "Luna decembrie:";
                cout << profit[i];
                cout << endl;
            }
        }

};

istream& operator >>(istream &in, Farmacie &ob)
{
    cout << "Dati numarul de angajati:(Maxim 9999)" << endl;
    in >> ob.nr_ang;
    try
    {
    if(ob.nr_ang < 0 || ob.nr_ang > 9999)
        throw(ob.nr_ang);
    }
    catch(int)
    {
        cout << "Valoarea introdusa este gresita.Introduceti alta valoare:" << endl;
        in >> ob.nr_ang;
    }
    cout << "Dati denumirea farmaciei:" << endl;
    in >> ob.denumire;
    cout << "Dati profiturile lunare ale farmaciei:(Numere intre 0 si 100)" <<endl;
    for(int i = 0; i < 12; i++)
    {
        if(i == 0)
        cout << "Luna ianuarie:";
        if(i == 1)
        cout << "Luna februarie:";
        if(i == 2)
        cout << "Luna martie:";
        if(i == 3)
        cout << "Luna aprilie:";
        if(i == 4)
        cout << "Luna mai:";
        if(i == 5)
        cout << "Luna iunie:";
        if(i == 6)
        cout << "Luna iulie:";
        if(i == 7)
        cout << "Luna august:";
        if(i == 8)
        cout << "Luna septembrie:";
        if(i == 9)
        cout << "Luna octombrie:";
        if(i == 10)
        cout << "Luna noiembrie:";
        if(i == 11)
        cout << "Luna decembrie:";
        in >> ob.profit[i];
        try
    {
    if(ob.profit[i] < 0 || ob.profit[i] > 100)
        throw(ob.profit[i]);
    }
    catch(double)
    {
        cout << "Valoarea introdusa este gresita.Introduceti alta valoare:" << endl;
        in >> ob.profit[i];
    }
    }
    return in;
}

class Farmacie_online : public Farmacie
{
    protected:
        string web;
        int vizitatori;
        double discount;
    public:
        Farmacie_online() : Farmacie()
        {
            web = "";
            vizitatori = 0;
            discount = 0;
        }

        Farmacie_online(string web, int vizitatori, double discount) : Farmacie()
        {
            this -> web = web;
            this -> vizitatori = vizitatori;
            this -> discount = discount;
        }

        Farmacie_online(const Farmacie_online &ob): Farmacie(ob)
        {
            web = ob.web;
            vizitatori = ob.vizitatori;
            discount = ob.discount;
        }

        int nr_vizitatori() const
        {
            return vizitatori;
        }

        ~Farmacie_online()
        {
        }

        const Farmacie_online& operator =(const Farmacie_online &ob)
        {
            if(this == &ob)
                return *this;
            this -> Farmacie :: operator =(ob);
            web = ob.web;
            discount = ob.discount;
            vizitatori = ob.vizitatori;
            return *this;
        }

        friend istream& operator >>(istream &in, Farmacie_online &ob);

        virtual void afisare()
        {
            Farmacie :: afisare();
            cout << "Web: ";
            cout << web <<endl;
            cout << "Numar de vizitatori: ";
            cout << vizitatori << endl;
            cout << "Discountul: ";
            cout << discount << endl;
        }
};

istream& operator >>(istream &in, Farmacie_online &ob)
{
    in >> (Farmacie&)ob;
    cout << "Dati numarul de vizitatori:(Maxim 99999)";
    in >> ob.vizitatori;
    try
    {
    if(ob.vizitatori < 0 || ob.vizitatori > 99999)
        throw(ob.vizitatori);
    }
    catch(int)
    {
        cout << "Valoarea introdusa este gresita.Introduceti alta valoare:" << endl;
        in >> ob.vizitatori;
    }
    cout << "Dati web:";
    in >> ob.web;
    cout << "Dati discount:(Numere intre 0 si 100)";
    in >> ob.discount;
    try
    {
    if(ob.discount < 0 || ob.discount > 100)
        throw(ob.discount);
    }
    catch(double)
    {
        cout << "Valoarea introdusa este gresita.Introduceti alta valoare:" << endl;
        in >> ob.discount;
    }
    return in;
}

template <class T>

class GestionareFarmacii
{
    protected:
        static int index;
        const int id;
        vector <T*> ob;
    public:
        GestionareFarmacii(int idd):id(idd)
        {
        }

        GestionareFarmacii(const GestionareFarmacii &ob)
        {
            ob = ob.ob;
        }

        ~GestionareFarmacii()
        {
            for(unsigned int i = 0; i < ob.size(); i++)
                delete ob[i];
        }

        const GestionareFarmacii& operator =(const GestionareFarmacii &ob)
        {
            if(&ob == this)
                return *this;
            ob = ob.ob;
            return *this;
        }

        GestionareFarmacii& operator +=(T &obb)
        {
            ob.push_back(&obb);
            index ++;
            return *this;

        }

       virtual void afisare()
        {
            for(unsigned int i = 0; i < ob.size(); i++)
            {
                if(Farmacie_online *N = dynamic_cast <Farmacie_online*> (ob[i]))
                    cout << "Farmacie online:" << endl;
                else if(Farmacie *N = dynamic_cast <Farmacie*> (ob[i]))
                    cout << "Farmacie" << endl;
                ob[i]->afisare();
                cout << endl;
            }
        }

        static void afisare_index()
        {
            cout << "index:" << index << endl;
        }

};

template <>
class GestionareFarmacii<int>
{
    protected:
    int nrvizitatori;
    public:
        GestionareFarmacii()
        {
            nrvizitatori = 0;
        }

        GestionareFarmacii(int nr)
        {
            nrvizitatori = nr;
        }

        GestionareFarmacii(GestionareFarmacii &ob)
        {
            nrvizitatori = ob.nrvizitatori;
        }

        const GestionareFarmacii& operator =(const GestionareFarmacii &ob)
        {
            if(this == &ob)
                return *this;
            nrvizitatori = ob.nrvizitatori;
        }

        void vizitatori(int nr)
        {
            nrvizitatori = nrvizitatori + nr;
        }

        friend ostream& operator <<(ostream& out, GestionareFarmacii &ob)
        {
            out << "Numarul de vizitatori ai farmaciilor online este:" << ob.nrvizitatori << endl;
            return out;
        }
};

int op = 1;
int n;

template <class T>
int GestionareFarmacii<T>::index = 0;

int main()
{
    cout << "Introduceti id-ul:(Numar intre 0 si 9999)" <<endl;
    cin >> n;
    try
    {
    if(n < 0 || n > 9999)
        throw(n);
    }
    catch(int)
    {
        cout << "Valoarea introdusa este gresita.Introduceti alta valoare:" << endl;
        cin >> n;
    }
    GestionareFarmacii<Farmacie> F(n);
    GestionareFarmacii<int> U;

    while(op != 0)
    {
    cout << "Introduceti optiunea: " << endl;
    cout << "1-Farmacie" << endl;
    cout << "2-Farmacie_online" << endl;
    cout << "0-Iesire si afisare farmacii introduse" << endl;
    cin >> op;
    if(op == 1)
    {
        Farmacie *M = new Farmacie;
        cin >> (*M);
        F += (*M);
    }
    if(op == 2)
    {
        Farmacie_online *M = new Farmacie_online;
        cin >> (*M);
        F += (*M);
        U.vizitatori(M -> nr_vizitatori());
    }
    }
    cout << endl;
    cout << endl;
    F.afisare();
    F.afisare_index();
    cout << U;
}
