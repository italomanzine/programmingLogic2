#ifndef WEIGHT_HPP
#define WEIGHT_HPP

#include <iostream>
#include "input.hpp"

using namespace std;
  
  //Classe que realiza as conversões de peso
  class Weight:public Input
  {
    public:
      void milligm_gm();
      void gm_milligm();
      void gm_kg();
      void kg_gm();
      void kg_mton();
      void mton_kg();
      void pound_kg();
      void kg_pound();
      void gm_pound();
      void pound_gm();
  };

  void Weight::milligm_gm()
  {
    cout<<"\n   miligrama= ";cin>>i;
    cout<<"\n   grama= "<<i*.001;
  }

  void Weight::gm_milligm()
  {
    cout<<"\n   grama= "; cin>>i;
    cout<<"\n   miligrama= "<<i*1000;
  }

  void Weight::pound_kg()
  {
    cout<<"\n   libra= "; cin>>i;
    cout<<"\n   kilograma= "<<i*.45359;
  }

  void Weight::gm_kg()
  { 
    cout<<"\n   Grama= ";cin>>i;
    cout<<"\n   kilograma= "<<i*.001;
  }

  void Weight::kg_gm()
  {    
    cout<<"\n   kilograma= ";cin>>i;
    cout<<"\n   Grama= "<<i*1000;
  }

  void Weight::kg_pound()
  {
    cout<<"\n   kilograma= ";cin>>i;
    cout<<"\n   libra= "<<2.20462*i;
  }

  void Weight::gm_pound()
  {
    cout<<"\n   grama= ";  cin>>i;
    cout<<"\n   libra= "<<i*.0022;
  }

  void Weight::pound_gm()
  {
    cout<<"\n   libra= "; cin>>i;
    cout<<"\n   grama= "<<i*453.59237;
  }

  void Weight::kg_mton()
  {
    cout<<"\n   kilograma= ";cin>>i;
    cout<<"\n   tonelada= "<<i*.001;
  }

  void Weight::mton_kg()
  {
    cout<<"\n   tonelada= "; cin>>i;
    cout<<"\n   kilograma= "<<i*1000;
  }


#endif