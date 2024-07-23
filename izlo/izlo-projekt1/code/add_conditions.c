#include <stddef.h>
#include "cnf.h"

//
// LOGIN: xborozv00
//

// Tato funkce by mela do formule pridat klauzule predstavujici podminku 1)
// Křižovatky jsou reprezentovany cisly 0, 1, ..., num_of_crossroads-1
// Cislo num_of_streets predstavuje pocet ulic a proto i pocet kroku cesty
// Pole streets ma velikost num_of_streets a obsahuje vsechny existujuci ulice
//    - pro 0 <= i < num_of_streets predstavuje streets[i] jednu existujici
//      ulici od krizovatky streets[i].crossroad_from ke krizovatce streets[i].crossroad_to
void at_least_one_valid_street_for_each_step(CNF *formula, unsigned num_of_crossroads, unsigned num_of_streets, const Street *streets)
{
    // Vytvoření nové klauzule pro každý krok cesty
    assert(formula != NULL);
    assert(num_of_crossroads > 0);
    assert(num_of_streets > 0);
    assert(streets != NULL);

    // ZDE PRIDAT KOD
    // Pro každý krok cesty
    for (unsigned i = 0; i < num_of_streets; ++i)
    {
        Clause *cl = create_new_clause(formula);
        for (unsigned j = 0; j < num_of_streets; ++j)
        {
            // Pro každou ulici přidat literál
            //( x(1, j, j) or x(1, j, j) ... or x(1, streets[num_of_streets - 1].crossed_from, streets[num_of_streets - 1])) and ( x(2, streets[j].crossed_from, streets[j].crossed_to) or ... ) ... - nejaka ulice se seznamu musi byt vybrana v kazdem kroce
            add_literal_to_clause(cl, true, i, streets[j].crossroad_from, streets[j].crossroad_to);
        }
    }
}

// Tato funkce by mela do formule pridat klauzule predstavujici podminku 2)
// Křižovatky jsou reprezentovany cisly 0, 1, ..., num_of_crossroads-1
// Cislo num_of_streets predstavuje pocet ulic a proto i pocet kroku cesty

void at_most_one_street_for_each_step(CNF *formula, unsigned num_of_crossroads, unsigned num_of_streets)
{
    assert(formula != NULL);
    assert(num_of_crossroads > 0);
    assert(num_of_streets > 0);

    // Pro každý krok cesty
    // ( not x(1, 1, 1) or not x(1, 1, 2) ) and ( not x(1, 1, 1) or not x(1, 1, 3) ) and ..
    // NAND
    // 1
    // 1
    // 1
    // 0
    for (unsigned i = 0; i < num_of_streets; ++i)
    {
        for (unsigned z = 0; z < num_of_crossroads; ++z)
        {
            for (unsigned k = 0; k < num_of_crossroads; ++k)
            {
                for (unsigned z1 = 0; z1 < num_of_crossroads; ++z1)
                {

                    for (unsigned k1 = 0; k1 < num_of_crossroads; ++k1)
                    {
                        // musime vybirat z ruznych ulic
                        if ((k1 != k) || (z1 != z))
                        {
                            Clause *cl = create_new_clause(formula);
                            add_literal_to_clause(cl, false, i, z, k);
                            add_literal_to_clause(cl, false, i, z1, k1);
                        }
                    }
                }
            }
        }
    }
}

// Tato funkce by mela do formule pridat klauzule predstavujici podminku 3)
// Křižovatky jsou reprezentovany cisly 0, 1, ..., num_of_crossroads-1
// Cislo num_of_streets predstavuje pocet ulic a proto i pocet kroku cesty

void streets_connected(CNF *formula, unsigned num_of_crossroads, unsigned num_of_streets)
{
    assert(formula != NULL);
    assert(num_of_crossroads > 0);
    assert(num_of_streets > 0);

    // ZDE PRIDAT KOD
    // ulice i+1 (konec muze mit kdekoliv) musi zacinat tam kde skoncila ulice i
    for (unsigned i = 0; i < num_of_streets; ++i)
    {
        for (unsigned z = 0; z < num_of_crossroads; ++z)
        {
            for (unsigned k = 0; k < num_of_crossroads; ++k)
            {

                Clause *cl = create_new_clause(formula);
                add_literal_to_clause(cl, false, i, z, k);

                for (int a = 0; a < num_of_crossroads; ++a)
                {

                    add_literal_to_clause(cl, true, i + 1, k, a);
                }
            }
        }
    }
}

// Tato funkce by mela do formule pridat klauzule predstavujici podminku 4)
// Křižovatky jsou reprezentovany cisly 0, 1, ..., num_of_crossroads-1
// Cislo num_of_streets predstavuje pocet ulic a proto i pocet kroku cesty
void streets_do_not_repeat(CNF *formula, unsigned num_of_crossroads, unsigned num_of_streets)
{
    assert(formula != NULL);
    assert(num_of_crossroads > 0);
    assert(num_of_streets > 0);

    for (unsigned i = 0; i < num_of_streets; ++i)
    {
        // pro kazdy krok i
        for (unsigned j = 0; j < num_of_streets; ++j)
        {
            if (i != j)
            {
                // pro kazdy jiny krok j
                for (unsigned z = 0; z < num_of_crossroads; ++z)
                {
                    for (unsigned k = 0; k < num_of_crossroads; ++k)
                    {
                        // pro kazdu dvojici krizovatek (z, k)
                        Clause *cl = create_new_clause(formula);
                        add_literal_to_clause(cl, false, i, z, k);
                        add_literal_to_clause(cl, false, j, z, k);
                    }
                }
            }
        }
    }
}
