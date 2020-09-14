% AnalyseA
analyseA(SEM) --> gnA(AGNT), gvA(ACT, OBJ),{SEM=..[ACT, AGNT, OBJ]}.
gnA(AGNT) --> npA(AGNT) | artA, ncA(AGNT).
gvA(ACT, OBJ) --> vA(ACT), gnA(OBJ).
artA -->[un].
npA(felix) -->[felix].
npA(quentin) -->[quentin].
ncA(chat) -->[chat].
ncA(homme) -->[homme].
ncA(felin) --> [felin].
ncA(vertebre) --> [vertebre].
vA(etre) -->[est].


% AnalyseB
analyseB(SEM2:-SEM1) --> gnB(AGNT), gvB(ACT, OBJ),{SEM1=..[ACT, X, AGNT]},{SEM2=..[ACT, X, OBJ]}.
gnB(AGNT) --> pronB, ncB(AGNT) | artB, ncB(AGNT) | pronB, npB(AGNT) | npB(AGNT).
gvB(ACT, OBJ) --> vB(ACT), gnB(OBJ).
artB -->[un].
pronB -->[tout].
ncB(felin) -->[felin].
ncB(vertebre) -->[vertebre].
ncB(chat) -->[chat].
ncB(homme) -->[homme].
npB(quentin) -->[quentin].
npB(felix) -->[felix].
vB(etre) -->[est].


% AnalyseC
analyseC(SEM) --> lvC(ACT, AGNT), gvC(ACT, OBJ),{SEM=..[ACT, AGNT, OBJ]}.
lvC(ACT, AGNT) --> vC(ACT), conjC, gnC(AGNT).
gvC(ACT, OBJ) --> vC(ACT), gnC(OBJ).
gnC(AGNT) --> npC(AGNT) | artC, ncC(AGNT).
artC -->[un].
conjC -->[ce, que].
ncC(felin) -->[felin].
ncC(chat) -->[chat].
ncC(homme) -->[homme].
ncC(vertebre) -->[vertebre].
npC(felix) -->[felix].
npC(quentin) -->[quentin].
vC(etre) -->[est].


% Go
go:- readln(Mots), analyseA(Sens, Mots, []), assert(Sens), write('ok '), nl, readln(Mots2), analyseB(Sens2, Mots2, []), assert(Sens2), write('ok '), nl, readln(Mots3), analyseC(Sens3, Mots3, []), clause(Sens3, Some), reponse(Sens, Some).


% Réponse (donne la réponse à la question posée et analysée par
% analyseC)
reponse(SensA, Some):- SensA==Some, write('oui').
reponse(SensA, Some):- not(SensA==Some), write('non').
