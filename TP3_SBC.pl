% Definition des operateurs
:- op(800, fx, si ),
op( 700, xfx, alors ),
op( 300, xfy, ou ),
op( 200, xfy, et ).
:- dynamic(fait/1).

% Données du problème : fait( X ) - à ajouter
fait(possede(tete)).
fait(possede(queue)).
fait(possede(quatreMembres)).


% Règles de la base de connaissances : si ... alors ... - à ajouter
si possede(tete) et possede(yeux) alors est(animal).

si possede(queue) et possede(squeletteInterieur) et est(animal) alors est(vertebre).
si possede(coquille) et possede(pied) et possede(tentacules) et est(animal) alors est(mollusque).
si possede(antennes) et possede(sixPattes) et possede(ailesMembranaires) et possede(squeletteExterieur) et est(animal) alors est(insecte).

si possede(quatreMembres) et est(vertebre) alors est(tetrapode).
si possede(rayonsNageoires) et est(vertebre) alors est(poisson).

si possede(elytre) et est(insecte) alors est(coleoptere).

si possede(poils) et possede(pavillonsOreilles) et est(tetrapode) alors est(mammifere).
si possede(ecaillesSoudees) et est(tetrapode) alors est(reptilien).

si possede(plumes) et possede(bec) et est(reptilien) alors est(oiseau).


si est(chauveSouris) alors est(mammifere).
si est(mammouth) alors est(mammifere).
si est(humain) alors est(mammifere).
si est(lapin) alors est(mammifere).

si est(pigeon) alors est(oiseau).
si est(poulet) alors est(oiseau).

si est(lezard) alors est(reptilien).

si est(saintPierre) alors est(poisson).
si est(truite) alors est(poisson).

si est(petitGris) alors est(mollusque).
si est(limnee) alors est(mollusque).

si est(hanneton) alors est(coleoptere).
si est(scarabee) alors est(coleoptere).
si est(coccinelle) alors est(coleoptere).

si est(criquet) alors est(insecte).




si est(animal) alors possede(tete).
si est(animal) alors possede(yeux).

si est(vertebre) alors possede(queue).
si est(vertebre) alors possede(squeletteExterieur).
si est(vertebre) alors est(animal).

si est(mollusque) alors possede(coquille).
si est(mollusque) alors possede(pied).
si est(mollusque) alors possede(tentacules).
si est(mollusque) alors est(animal).

si est(insecte) alors possede(antennes).
si est(insecte) alors possede(sixPattes).
si est(insecte) alors possede(ailesMembranaires).
si est(inestce) alors possede(squeletteExterieur).
si est(insecte) alors est(animal).

si est(tetrapode) alors possede(quatreMembres).
si est(tetrapode) alors est(vertebre).

si est(poisson) alors possede(rayonsNageoires).
si est(poisson) alors est(vertebre).

si est(coleoptere) alors possede(elytre).
si est(coleoptere) alors est(insecte).

si est(mammifere) alors possede(poil).
si est(mammifere) alors possede(pavillonsOreilles).
si est(mammifere) alors est(tetrapode).

si est(reptilien) alors possede(ecaillesSoudees).
si est(reptilien) alors est(tetrapode).

si est(oiseau) alors possede(plumes).
si est(oiseau) alors possede(bec).
si est(oiseau) alors est(reptilien).



% ch_arriere/1 : moteur d inference fonctionnant en chainage arriere
ch_arriere( But ) :- est_vrai( But ).
est_vrai( Proposition ) :- fait( Proposition ).
est_vrai( Proposition ) :- si Condition alors Proposition, est_vrai( Condition ).
est_vrai( Cond1 et Cond2 ) :- est_vrai( Cond1 ), est_vrai( Cond2 ).
est_vrai( Cond1 ou Cond2 ) :- est_vrai( Cond1 ) ; est_vrai( Cond2 ).


% ch_avant/0 : moteur d inference fonctionnant en chainage avant
ch_avant :-
nouveau_fait( Nouveau ), !, write( 'Nouveau fait : ' ), write( Nouveau ), nl, assert( fait( Nouveau ) ), ch_avant.
ch_avant :-
write( 'Plus de nouveaux faits déduits, la BC est saturée.'), nl.
nouveau_fait( NouvFait ) :-
si Condition alors NouvFait, not( fait(NouvFait) ), recherche_fait( Condition ).
recherche_fait( Condition ) :-
fait( Condition ).
recherche_fait( Cond1 et Cond2 ) :-
recherche_fait( Cond1 ), recherche_fait( Cond2 ).
recherche_fait( Cond1 ou Cond2 ) :-
recherche_fait( Cond1 ) ; recherche_fait( Cond2 ).
