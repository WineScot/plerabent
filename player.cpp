#include "player.h"
#include <cstdlib>
#include <windows.h>
#include "monster.h"
#include "event.h"
#include "plansza.h"
#include "funkcje.h"


Player::Player(Plansza* p)
{
    position=1;
    this->p=p;
}

void Player::ustawimie()
{
    std::cout<<"Podaj swoje imię!"<<std::endl;
    std::cin>>name;
}

void Player::battle(Event* eve)
{
    srand(hp);
    int monsterHp = eve->getM()->getHp();
    int monsterAtt = eve->getM()->getAtt();
    int monsterDef = eve->getM()->getDef();
    int c_damage=0;//otrzymane obrazenia (Druid)
    bool tour=rand()%2; //losowanie tury
    system(clear);
    if(tour) std::cout<<"Atakujesz jako pierwszy!"<<std::endl;
    else std::cout<<"Przeciwnik atakuje jako pierwszy!"<<std::endl;
    sleep(1000);
    while(hp>0 && monsterHp>0)
    {
        int base=rand()%6+1; //rzut kostką
        if(tour)
        {
            int w_attack = attack;
            system(clear);
            showstats();
            eve->getM()->showstats(monsterHp);
            std::cout<<"Twoja tura!"<<std::endl;
            sleep(500);
            WAIT;
            std::cout<<"Rzut kostką: "<<base<<std::endl;
            if(critical>0)
            {
              int w_crit=rand()%100+1;
              if(w_crit<=critical)
              {
                    w_attack*=2;
                    std::cout<<"TRAFIENIE KRYTYCZNE!\n";
              }
            }
            base+=w_attack-monsterDef;
            base=std::max(base,1);
            monsterHp-=base;
            sleep(500);
            std::cout<<"Zadałeś "<<base<<" obrażeń"<<std::endl;
            sleep(1000);
        }
        else
        {
            system(clear);
            showstats();
            eve->getM()->showstats(monsterHp);
            std::cout<<"Tura przeciwnika!"<<std::endl;
            sleep(500);
            std::cout<<"Rzut kostką: "<<base<<std::endl;
            base+=monsterAtt-defence;
            base=std::max(base,1);
            hp-=base;
            std::cout<<"Przeciwnik zadał "<<base<<" obrażeń"<<std::endl;
            c_damage+=base;
            sleep(1000);
        }
        tour=!tour;
    }
    system(clear);
    if(hp<=0) std::cout<<"Zginąłeś!"<<std::endl;
    else
    {
        std::cout<<"Pokonałeś przeciwnika!"<<std::endl;
        eve->wyswietl_bonusy();
        c_event(eve);
        if(heal)
        {
            std::cout<<"Umiejętność druida";
            for(int i=0;i<3;i++)
            {
                Sleep(1000);
                std::cout<<".";
            }
            std::cout<<"\n";
            int l_heal=rand()%100+1;
            if(l_heal<30)
            {
                hp=hp+c_damage/2; //jest 43% szans na odnowienie 50% obrazen
                std::cout<<c_damage/2<<" zostało odnowione\n";
            }
            else
                std::cout<<"Użycie umiejętności się nie powiodło :(\n";

        }
    }
}

void showpoints(int a, int b)
{
    std::cout<<"'Jest "<<a<<":"<<b<<" dla mnie!'"<<std::endl;
}

void odpow(std::string &odp)
{
    int now=GetTickCount();
    getline(std::cin,odp);
    std::cout<<std::endl;
    if(GetTickCount()-now>5000) odp="babla";
}

void Player::BossBattle()
{
    std::cout<<"Oto docierasz do końca swojej przygody! Przechodziłeś przez góry, lasy, szkoły, miasta, a teraz docierasz do miejsca ostatecznego... Oto przed tobą drzwi, a na nich napis: 46.";
    std::cout<<std::endl;
    std::cout<<"Przed tobą pojawia się: Sir Kamiński!!!"<<std::endl;
    std::cout<<"Wkraczasz na środek sali, na sobie czujesz wzrok zdziwionych ludzi siedzących w ławkach. Jednak o wiele bardziej czujesz przeszywający cię wzrok Sir Kamińskiego."<<std::endl;
    std::cout<<"'To może jakieś panie do tablicy?' - odzywa się Sir Kamiński - 'panie "<<name<<", zapraszam!'"<<std::endl;
    WAIT;
    system(clear);
    int KP=0, PP=0; //punkty
    std::string odp;

    std::cout<<"'Na każde pytanie masz 5 sekund, jeśli odpowiesz dobrze, ale po czasie - punkt dla mnie.'"<<std::endl;
    WAIT;
    system(clear);

    std::cin.ignore();

    std::cout<<"'Jakie było pierwsze zwierzę w kosmosie?'"<<std::endl;
    odpow(odp);
    if(odp=="mucha" || odp=="muszka" || odp=="muszka owocowa") PP++;
    else KP++;
    showpoints(KP,PP);
    WAIT;
    system(clear);

    std::cout<<"'Ile wynosi odległość Ziemi od Słońca (au)?'"<<std::endl;
    odpow(odp);
    if(odp=="1") PP++;
    else KP++;
    showpoints(KP,PP);
    WAIT;
    system(clear);

    std::cout<<"'Bezpośrednia zmiana ciała stałego w gaz to?'"<<std::endl;
    odpow(odp);
    if(odp=="resublimacja") PP++;
    else KP++;
    showpoints(KP,PP);
    WAIT;
    system(clear);

    std::cout<<"'Czy amper jest jednostką układu SI (tak/nie)?'"<<std::endl;
    odpow(odp);
    if(odp=="nie") PP++;
    else KP++;
    showpoints(KP,PP);
    WAIT;
    system(clear);

    std::cout<<"'Podaj treść drugiego prawa Maxwella.'"<<std::endl;
    odpow(odp);
    if(1!=1) PP++;
    else KP++;
    showpoints(KP,PP);
    WAIT;
    system(clear);

    std::cout<<"Śmiechów dochodzących z sali nie było końca."<<std::endl;
    std::cout<<"'No dobra, najwyższa pora, aby to zakończyć...' - powiedział Sir Kamiński"<<std::endl;
    WAIT;
    system(clear);

    Monster* Kamis = new Monster;
    Kamis->boss(PP);
    Event* bossbattle = new Event(0,0,0);
    bossbattle->ustaw_potwora(*Kamis);
    battle(bossbattle);
    std::cout<<"'Gratuluję! Jeszcze nikomu nie udało się mnie pokonać. No ale nad fizyką musisz jeszcze popracować...' - powiedział Sir Kamiński"<<std::endl;
    std::cout<<"Widzisz jak wyciąga z kieszeni cukierka. Rzuca go w twoją stronę. Łapiesz go."<<std::endl;
    std::cout<<"'Masz na zachętę. Możesz sobie postawić kropkę. Ale ponieważ nie znałeś treści drugiego prawa Maxwella, to kołeczek będzie.'"<<std::endl;
    WAIT;
    system(clear);
    std::cout<<"Tak oto kończy się twoja przygoda... "<<std::endl;
    showstats();
    koniec=true;
}

void Player::c_event(Event *e)
{
    hp+=e->getHp();
    attack+=e->getAtt();
    defence+=e->getDef();
}

bool Player::Koniec()
{
    return koniec;
}

void Player::p_move()
{
    int mov=rand()%12+1;
    std::cout<<"Ruch: "<<mov<<std::endl;
    position+=mov; //tymczasowe
    for(int i=0; i<mov; i++)
    {
        p->addPos();
        sleep(500);
        system(clear);
        if(!(rand()%5)) qte(this);
        p->wyswietl();
        showstats();
        if(p->Czy()==true)
        {
            koniec=true;
            std::cout<<"Gracz dotarł do mety\n";
            break;
        }
    }

}

void Player::showstats()
{
    std::cout<<"Twoje statystyki:"<<std::endl;
    std::cout<<"Nazwa: "<<name<<std::endl;
    std::cout<<"Punkty życia: "<<hp<<std::endl;
    std::cout<<"Atak: "<<attack<<std::endl;
    std::cout<<"Obrona: "<<defence<<std::endl;
}

void Player::odejmijhp(int val)
{
    hp-=val;
}

void Player::addattack(int val)
{
    attack+=val;
}

int Player::getHp()
{
    return hp;
}

int Player::getAtt()
{
    return attack;
}

int Player::getDef()
{
    return defence;
}

bool Player::getDodge()
{
    return dodge;
}


