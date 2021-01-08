#pragma once


class Intcell {
    friend class Intlist;

public:
    Intcell():adresse_left_cell(nullptr), adresse_right_cell(nullptr){
        value = *new int(0);
    } //initialisation d'une cellule vide

    Intcell(int argument, Intcell* adresse_left_cell, Intcell* adresse_right_cell): adresse_left_cell(*new Intcell* (adresse_left_cell)), adresse_right_cell(*new Intcell* (adresse_right_cell)) {
        value = *new int(0);
        value = argument;
    }

    Intcell(int first_value): adresse_left_cell(nullptr), adresse_right_cell(nullptr){
        value= *new int(0);
        value= first_value;
    } //initialisation de la première cellule d'une liste
        
    Intcell(const Intcell& rcell): value( *new int(rcell.value) ){
        adresse_left_cell = rcell.adresse_left_cell;
        adresse_right_cell = rcell.adresse_right_cell;
    }



 




private:
    int value;
    
    Intcell* adresse_left_cell;//adresse de la cellule de gauche
    Intcell* adresse_right_cell;//adresse de la cellule de droite

};


class Intlist {
    friend class Intcell;

    public:
        Intlist(){
            Intcell first_cell (0);
            adresse_first_cell = &first_cell;
            adresse_last_cell = &first_cell;
        }
        bool is_empty(){
            return ((*adresse_first_cell).value == 0);
        }

        void add_front(int argument){
            if(is_empty()){
                Intcell cell(argument);
                
                adresse_first_cell = &cell;
                adresse_last_cell= &cell;
            }
            else{
                Intcell cell(argument, nullptr, adresse_first_cell);
                (*adresse_first_cell).adresse_left_cell = &cell;
                adresse_first_cell = &cell;
            }
        }

        void add_back( int argument){
            if(is_empty()){
                Intcell cell(argument);
                
                adresse_first_cell = &cell;
                adresse_last_cell= &cell;
            }
            else{
                Intcell cell(argument, adresse_last_cell, nullptr);
                (*adresse_last_cell).adresse_right_cell = &cell;
                adresse_last_cell = &cell;
            }           
        }

        void remove_front (){
            if( is_empty() ){}
            else{
                adresse_first_cell = (*adresse_first_cell).adresse_right_cell;
                (*adresse_first_cell).adresse_left_cell = nullptr;
            }
        }
        void remove_back (){
            if (is_empty()){}
            else{
                adresse_last_cell = (*adresse_last_cell).adresse_left_cell;
                (*adresse_last_cell).adresse_right_cell = nullptr;
            }
        }
        bool search( int argument){
            Intcell* adresse_iterable = adresse_first_cell;
            int fin = 0;
            bool answer = false;
            while((*adresse_iterable).value != 0 and fin == 0){
                if ((*adresse_iterable).value == argument){
                        answer = true;
                        fin = 1;

                }
                else if ((*adresse_iterable).adresse_right_cell != nullptr){
                    adresse_iterable = (*adresse_iterable).adresse_right_cell;
                }
                else{
                    fin = 1;
                }
            }
            return answer;
        }
        
        void print_list(){
            Intcell* adresse_iterable = adresse_first_cell;
            int fin = 0;
            while((*adresse_iterable).value != 0 and fin == 0){
                std::cout<< (*adresse_iterable).value << '\n';
                if ((*adresse_iterable).adresse_right_cell != nullptr){
                adresse_iterable = (*adresse_iterable).adresse_right_cell;

                }
                else{
                    fin = 1;
                }
            }
        }

    
    private:
        Intcell* adresse_first_cell;
        Intcell* adresse_last_cell;
};