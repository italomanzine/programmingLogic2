#include "input.hpp"
#include "lenght.hpp"
#include "weight.hpp"

int main()
{
    Length b;
    Weight c;

    //Variáveis para seleção das opções
    int x,y;

    while(1)
    {
      cout<<"\t\t\tBEM-VINDO AO CONVERSOR DE UNIDADES\n";
      cout<<"\n      TIPO"<<"\n     ------";
      cout<<"\n  1: COMPRIMENTO\n" << "  2: PESO\n"<<"  3: SAIR\n";
      cout<<"\n\nEscolha seu tipo de conversor:" ;
      cin>>x;
      //Sub menu de conversor de comprimento
      if(x==1)
        {           
          cout<<"\n\n escolha a unidade de conversao:\n";

          cout<<"\n  1 : mm-m";
          cout<<"\n  2 : m-mm";
          cout<<"\n  3 : cm-m";
          cout<<"\n  4 : m-cm";
          cout<<"\n  5 : cm_km";
          cout<<"\n  6 : km-cm";
          cout<<"\n  7 : m-milha";
          cout<<"\n  8 : milha-m";
          cout<<"\n  9 : km-milha";
          cout<<"\n 10 : milha-km";
          cout<<"\n 11 : pes-m";
          cout<<"\n 12 : m-pes";
          cout<<"\n 13 : polegada-m";
          cout<<"\n 14 : m-polegada";
          cout<<"\n 15 : yard-m";
          cout<<"\n 16 : m-yard";
          cout<<"\n 17 : Voltar ao menu principal";


          while(1)
            {
              cout<<"\n\n Digite sua escolha= ";
              cin>>y;

              if (y==1)
                { b.mm_m(); }
                else if(y==2)
                    { b.m_mm(); }
                else if (y==3)
                    { b.cm_m(); }
                else if (y==4)
                    { b.m_cm(); }
                else if (y==5)
                    { b.cm_km(); }
                else if (y==6)
                    {  b.km_cm(); }
                else if (y==7)
                    {  b.m_mile(); }
                else if (y==8)
                    {   b.mile_m(); }
                else if (y==9)
                    {   b.km_mile(); }
                else if (y==10)
                    {  b.mile_km(); }
                else if (y==11)
                    {  b.feet_m(); }
                else if (y==12)
                    { b.m_feet(); }
                 else if (y==13)
                    { b.inch_m();}
                else if(y==14)
                    { b.m_inch();}
                else if (y==15)
                    {b.yard_m();}
                else if (y==16)
                    {b.m_yard();}
                else if (y==17)
                    {break;}
            }
           }

            //Sub menu de conversor de peso 
            else if(x==2)
            {                  
              cout<<"\n\nescolha a unidade de conversao :\n";

              cout<<"\n  1: Miligm-Grama";
              cout<<"\n  2: Grama-miligm";
              cout<<"\n  3: Grama-kilograma";
              cout<<"\n  4: kiloGrama-Grama";
              cout<<"\n  5: libra-kilograma";
              cout<<"\n  6: kilograma-libra";
              cout<<"\n  7: Grama-libra";
              cout<<"\n  8: libra-grama";
              cout<<"\n  9: kilograma-tonelada";
              cout<<"\n 10: tonelada-Kilograma";
              cout<<"\n 11: Voltar ao menu";

              while(1)
              {
                cout<<"\n\nDigite sua escolha= ";
                cin>>y;

                if (y==1)
                {c.milligm_gm();}
                  else if (y==2)
                    {c.gm_milligm();}
                  else if (y==3)
                    {c.gm_kg();}
                  else if (y==4)
                    {c.kg_gm();}
                  else if (y==5)
                    {c.pound_kg();}
                  else if (y==6)
                    {c.kg_pound();}
                  else if (y==7)
                    {c.gm_pound();}
                  else if (y==8)
                    {c.pound_gm();}
                  else if (y==9)
                    {c.kg_mton();}
                  else if (y==10)
                    {c.mton_kg();}
                  else if (y==11)
                  {break;}
              }
        }

        //Finaliza o programa
        else if(x==3){ break;}

    }


}