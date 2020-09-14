from tkinter import *
from tkinter import messagebox
from tkinter.ttk import Combobox
from random import randint, shuffle, choice
import webbrowser
from enum import Enum

NB_MAX_JOUEURS = 3
NB_MIN_JOUEURS = 2
NB_MAX_LANCERS = 3
NOMBRE_DES_DU_JEU = 5
DICTIONNAIRE = {"NB_JOUEURS": 0, "AS_SONT_JOKER":False, "NB_PARTIE_JOUEES":0, "LISTE_JOUEUR":[], "LIMITE_LANCER":NB_MAX_LANCERS, "PREMIER_JOUEUR":0, "NUM_LANCER":0}



# ****************************************************************************

class TypeCombinaison(Enum):
    """Énumeration des types de combinaisons possibles."""
    QUINTON = 7
    CARRE = 6
    FULL = 5
    BRELAN = 4
    SEQUENCE = 3
    DEUX_PAIRES = 2
    UNE_PAIRE = 1
    AUTRE = 0

    def __str__(self):
        """
        Permet d'afficher le nom de la combinaison obtenue
        Returns(str): Un string de la combinaison obtenue

        """
        if self == TypeCombinaison.QUINTON:
            return "Quinton"
        if self == TypeCombinaison.CARRE:
            return "Carre"
        if self == TypeCombinaison.FULL:
            return "Full"
        if self == TypeCombinaison.BRELAN:
            return "Brelan"
        if self == TypeCombinaison.SEQUENCE:
            return "Sequence"
        if self == TypeCombinaison.DEUX_PAIRES:
            return "Deux paires"
        if self == TypeCombinaison.UNE_PAIRE:
            return "Une paire"
        if self == TypeCombinaison.AUTRE:
            return "Autre"


# ****************************************************************************
class Parametres_partie(Toplevel):
    """Configurations de la partie"""

    def __init__(self, parent):
        super().__init__(parent)
        self.title("Configuration de la partie")
        self.geometry("400x200")

        # ---- On prend le contrôle ----
        self.parent = parent
        self.transient(parent)
        self.grab_set()

        self.nombre_joueurs = 0
        self.as_sont_joker = False

        self.nom_joueurs = []

        # ---- Labels pour la fenêtre Configuration de la partie ----
        self.instruction_nb_joueurs = Label(self, text="Nombre de joueur")
        self.instruction_nb_joueurs.grid(row=0, column=0, padx=5, pady=5)

        self.var_nb_joueurs = IntVar()
        self.var_nb_joueurs.trace('w', self.selection_nb_joueur)

        self.box_nb_joueurs = Combobox(self, textvariable=self.var_nb_joueurs, values=[2, 3])
        self.box_nb_joueurs.grid(row=0, column=1, padx=5, pady=5)

        self.instruction_nb_joueurs = Label(self, text="As comme joker?")
        self.instruction_nb_joueurs.grid(row=1, column=0, padx=5, pady=5)

        self.var_as_joker = StringVar()
        self.var_as_joker.trace('w', self.selection_nb_joueur)

        self.box_as_joker = Combobox(self, textvariable=self.var_as_joker, values=["Non", "Oui"])
        self.box_as_joker.grid(row=1, column=1, padx=5, pady=5)

        # ----- Entrer le nom des joueurs -----
        self.instruction_nom_joueurs = Label(self, text="Entrez le nom des joueurs :")
        self.list_labels_nom_joueurs = []
        self.list_entrees_nom_joueurs = []
        self.list_vars_nom_joueurs = []
        for i in range(NB_MAX_JOUEURS):
            self.list_vars_nom_joueurs.append(StringVar(value='Joueur{}'.format(i + 1)))
            self.list_labels_nom_joueurs.append(Label(self, text="Nom du joueur{}".format(i + 1)))
            self.list_entrees_nom_joueurs.append(Entry(self, width=10,
                                                       textvariable=self.list_vars_nom_joueurs[i]))
        self.erreur_nom_joueurs = Label(self, text="Erreur! Vous devez entrez un nom pour "
                                                   "chacun des joueurs avant de poursuivre.")

        self.bouton_commencer_partie = Button(self, text="Commencer", command=self.valider)

        self.box_as_joker.current(0)
        self.box_nb_joueurs.current(0)

        self.protocol("WM_DELETE_WINDOW", self.valider)
        self.wait_window()

    def valider(self):
        """
        Valide le nombre de participants afin de pouvoir débuter la partie
        Returns:

        """
        valide = False
        try:
            self.nombre_joueurs = self.var_nb_joueurs.get()
            self.as_sont_joker = self.var_as_joker.get() == 'Oui'
            self.nom_joueurs = [self.list_vars_nom_joueurs[i].get()
                                for i in range(self.nombre_joueurs)]
            if not (2 <= self.nombre_joueurs <= 3):
                messagebox.showerror("Erreur",
                                     "Le nombre de joueur de la partie entre 2 et 3")
            else:
                valide = True
        except:
            messagebox.showerror("Erreur",
                                 "Le nombre de joueur de la partie doit être entre 2 et 3")

        if valide:
            # On redonne le contole à la fenêtre parent et on ferme la fenêtre.
            self.ajouter_au_dictionnaire()
            self.grab_release()
            self.parent.focus_set()
            self.destroy()

    def selection_nb_joueur(self, index, value, op):
        """
        Affiche le nom des joueurs, le bouton commencer et la boite d'entrée de données.
        Args:
            index:
            value:
            op:

        Returns:

        """
        for i in range(NB_MAX_JOUEURS):
            self.list_labels_nom_joueurs[i].grid_forget()
            self.list_entrees_nom_joueurs[i].grid_forget()
        for i in range(self.var_nb_joueurs.get()):
            self.list_labels_nom_joueurs[i].grid(row=2 + i, column=0, padx=5, pady=5)
            self.list_entrees_nom_joueurs[i].grid(row=2 + i, column=1, padx=5, pady=5)
        self.bouton_commencer_partie.grid_forget()
        self.bouton_commencer_partie.grid(row=3 + i, column=1, padx=5, pady=5)

    def get_values_saved(self):
        """
        Permet de récupérer les données de self.nombre_joueurs, self.as_sont_joker et self.nom_joueurs
        Returns: self.nombre_joueurs, self.as_sont_joker, self.nom_joueurs

        """
        return self.nombre_joueurs, self.as_sont_joker, self.nom_joueurs

    def ajouter_au_dictionnaire(self):
        """
        Ajoute les donnees requises pour la sauvegarde au DICTIONNAIRE
        Returns:

        """
        DICTIONNAIRE["NB_JOUEURS"] = self.nombre_joueurs
        DICTIONNAIRE["AS_SONT_JOKER"] = self.as_sont_joker
        DICTIONNAIRE["NB_PARTIE_JOUEES"] = 0
        DICTIONNAIRE["LIMITE_LANCER"] = NB_MAX_LANCERS
        DICTIONNAIRE["NUM_LANCER"] = 0
        i = 0
        while i < len(self.nom_joueurs):
            DICTIONNAIRE["JOUEUR"] = self.nom_joueurs[i]
            DICTIONNAIRE["COMBINAISON{}".format(self.nom_joueurs[i])] = "autre"
            i += 1
        DICTIONNAIRE["LISTE_JOUEUR"] = self.nom_joueurs
        for joueur in self.nom_joueurs:
            DICTIONNAIRE["NB_VICTOIRE{}".format(joueur)] = 0



# ****************************************************************************

class Jouer_tour(Toplevel):
    """Fenêtre de jeu pour la partie"""

    def __init__(self, parent, nom_joueur, nb_des_a_lancer=NOMBRE_DES_DU_JEU, nb_maximum_lancer=NB_MAX_LANCERS):
        super().__init__(parent)
        self.title("Jouer tour du joueur")
        self.geometry("460x250")

        # On prend le contrôle
        self.parent = parent
        self.transient(parent)
        self.grab_set()

        self.nom_joueur = nom_joueur
        self.nb_des_a_lancer = nb_des_a_lancer
        self.nb_maximum_lancer = nb_maximum_lancer

        self.resultat_lancer = {}
        self.resultat_lancer[nom_joueur] = ['_'] * 5

        self.index_a_relancer = []
        self.des_a_relancer = []

        self.num_lancer = DICTIONNAIRE["NUM_LANCER"]
        self.nb_partie_jouees = DICTIONNAIRE["NB_PARTIE_JOUEES"]
        self.combinaison_actuelle = ""
        self.nb_victoires = 0

        self.images_des = {}
        self.label_resultat_lancer_dict = {}
        self.index_checkbox = []

        resultat_joueur = self.resultat_lancer[nom_joueur]

        DICTIONNAIRE['RESULTAT:{}'.format(self.resultat_lancer[nom_joueur])] = resultat_joueur
        DICTIONNAIRE["COMBINAISON{}".format(self.resultat_lancer[nom_joueur])] = str(self.combinaison_actuelle)

        # ---- Éléments affichage de la partie ----
        self.frame_entete = Frame(self)
        self.bouton_frame = Frame(self)
        self.frame_combinaison = Frame(self)
        self.bouton_lancer_passer = Frame(self)

        self.frame_entete.grid(row=0, column=0)
        self.bouton_frame.grid(row=1, column=0)
        self.frame_combinaison.grid(row=3, column=0)
        self.bouton_lancer_passer.grid(row=1, column=1)

        self.label_accueil_joueur = Label(self.frame_entete,
                                          text="C'est au tour de {} de jouer son tour !".format(self.nom_joueur))
        self.label_accueil_joueur.grid(row=0, column=0, padx=5, pady=5)

        self.label_combinaison = Label(self.frame_combinaison)

        self.bouton_lancer = Button(self.bouton_lancer_passer, text="Lancer")
        self.bouton_lancer.bind('<Button-1>', lambda event: self.lancer_des())
        self.bouton_lancer.grid(row=1, column=0)

        self.bouton_passer = Button(self.bouton_lancer_passer, text="Passer")
        self.bouton_passer.bind('<Button-1>', lambda event: self.passer_au_suivant())
        self.bouton_passer.grid(row=3, column=0)

        i = 0
        while i < 5:
            self.images_des[nom_joueur + str(i)] = Checkbutton(self.bouton_frame, text='Dé {}'.format(i + 1), onvalue=1)
            self.index_checkbox.append(nom_joueur + str(i))
            self.images_des[nom_joueur + str(i)].grid(row=2, column=i, padx=10, pady=10)
            i += 1

        # On lie un clic sur le Canvas à une méthode.
        self.images_des[nom_joueur + str(0)].bind('<Button-1>',
                                                  lambda event: self.selectionner_des('<Button-1>',
                                                                                      self.index_checkbox[0]))
        self.images_des[nom_joueur + str(1)].bind('<Button-1>',
                                                  lambda event: self.selectionner_des('<Button-1>',
                                                                                      self.index_checkbox[1]))
        self.images_des[nom_joueur + str(2)].bind('<Button-1>',
                                                  lambda event: self.selectionner_des('<Button-1>',
                                                                                      self.index_checkbox[2]))
        self.images_des[nom_joueur + str(3)].bind('<Button-1>',
                                                  lambda event: self.selectionner_des('<Button-1>',
                                                                                      self.index_checkbox[3]))
        self.images_des[nom_joueur + str(4)].bind('<Button-1>',
                                                  lambda event: self.selectionner_des('<Button-1>',

                                                                                      self.index_checkbox[4]))
        # ---- Initialiser le premier lancer de dés ----
        self.lancer_des()

    def lancer_des(self):
        """
        Effectue le lancer des dés, détermine la combinaison actuelle,

        Returns:

        """
        resultat_joueur = self.resultat_lancer[self.nom_joueur]
        if self.des_a_relancer != []:
            for i in (self.des_a_relancer):
                valeurs_obtenues = [randint(1, 6) for _ in range(1)]
                resultat_joueur[i] = valeurs_obtenues[0]
        else:
            resultat_joueur = [randint(1, 6) for _ in range(NOMBRE_DES_DU_JEU)]

        self.resultat_lancer[self.nom_joueur] = resultat_joueur

        # ---- Determiner la combinaison actuelle ----
        if DICTIONNAIRE["AS_SONT_JOKER"] == True:
            self.combinaison_actuelle = self.determiner_type_combinaison()
        else:
            self.combinaison_actuelle = self.determiner_type_combinaison_sans_as()


        # ---- Mise à jour des données ----
        self.num_lancer += 1
        del self.des_a_relancer[:]
        self.nb_des_a_lancer = 0
        self.clear_table()
        self.mise_a_jour_des()
        self.label_combinaison.grid_forget()
        self.afficher_combinaison()

        # ---- Établir une limite de lancer pour le prochain joueur ----
        if self.num_lancer == self.nb_maximum_lancer:
            self.empecher_lancer()
            # DICTIONNAIRE["LIMITE_LANCER"] = self.num_lancer
            self.passer_au_suivant()
        else:
            self.wait_window()

    def determiner_type_combinaison(self):
        """
        Détermine le type de la combinaison lorsque As_sont_joker est True.
        Returns(TypeCombinaison): Le type de la combinaison.

        """

        resultat_joueur = self.resultat_lancer[self.nom_joueur]

        codage = [0] * 6
        for i in resultat_joueur:
            j = 0
            face_du_de = [1, 2, 3, 4, 5, 6]
            while j < 6:
                if face_du_de[j] == i:
                    codage[j] += 1
                j += 1

        if 5 in codage:
            return TypeCombinaison.QUINTON
        if 4 in codage:
            if codage[0] != 0:
                return TypeCombinaison.QUINTON
            else:
                return TypeCombinaison.CARRE
        if 3 in codage and 2 in codage:
            if codage[0] != 0:
                return TypeCombinaison.QUINTON
            else:
                return TypeCombinaison.FULL
        if 3 in codage:
            if codage[0] != 0:
                if codage[0] == 1:
                    return TypeCombinaison.CARRE
                elif codage[0] == 2:
                    return TypeCombinaison.QUINTON
                elif codage[0] == 3:
                    return TypeCombinaison.CARRE
            else:
                return TypeCombinaison.BRELAN
        if codage.count(1) == 5:
            return TypeCombinaison.SEQUENCE
        if codage.count(2) == 2:
            if codage[0] != 0:
                if codage[0] == 2:
                    return TypeCombinaison.CARRE
                elif codage[0] == 1:
                    return TypeCombinaison.FULL
            else:
                return TypeCombinaison.DEUX_PAIRES
        if codage.count(2) == 1 and 3 not in codage:
            if codage[0] != 0:
                return TypeCombinaison.BRELAN
            else:
                return TypeCombinaison.UNE_PAIRE
        else:
            return TypeCombinaison.AUTRE

    def determiner_type_combinaison_sans_as(self):
        """
        Détermine le type de la combinaison lorsque As_sont_joker est False.
        Returns(TypeCombinaison): Le type de la combinaison.

        """
        resultat_joueur = self.resultat_lancer[self.nom_joueur]

        codage = [0] * 6
        for i in resultat_joueur:
            j = 0
            face_du_de = [1, 2, 3, 4, 5, 6]
            while j < 6:
                if face_du_de[j] == i:
                    codage[j] += 1
                j += 1

        if 5 in codage:
            return TypeCombinaison.QUINTON
        if 4 in codage:
            return TypeCombinaison.CARRE
        if 3 in codage and 2 in codage:
            return TypeCombinaison.FULL
        if 3 in codage:
            return TypeCombinaison.BRELAN
        if codage.count(1) == 5:
            return TypeCombinaison.SEQUENCE
        if codage.count(2) == 2:
            return TypeCombinaison.DEUX_PAIRES
        if codage.count(2) == 1 and 3 not in codage:
            return TypeCombinaison.UNE_PAIRE
        else:
            return TypeCombinaison.AUTRE

    def selectionner_des(self, event, index_checkbox):
        """
        Permet de sélectionner les dés selon le checkbox qui est coché.
        Remet la valeur du checkbox à 0
        Args:
            event:
            index_checkbox: L'index du checkbox qui a été sélectionné

        Returns:

        """

        checkbox = self.images_des[index_checkbox]
        index_des_a_relancer = int(index_checkbox[-1])
        if checkbox['onvalue'] == 1:
            self.des_a_relancer.append(index_des_a_relancer)
            self.nb_des_a_lancer += 1
            checkbox['onvalue'] = 0
            checkbox.deselect()
        elif checkbox['onvalue'] == 0:
            self.des_a_relancer.remove(index_des_a_relancer)
            self.nb_des_a_lancer -= 1
            checkbox['onvalue'] = 1
            checkbox.select()

    def clear_table(self):
        """
        Mettre à jour les checkbox
        Returns:

        """
        for key, value in self.images_des.items():
            checkbox = self.images_des[key]
            checkbox.deselect()
            checkbox['onvalue'] = 1
        self.update()

    def mise_a_jour_des(self):
        """
        Mettre à jour le résultat des dés et afficher le résultat sur un Label

        Returns:

        """
        resultat_joueur = self.resultat_lancer[self.nom_joueur]

        i = 0
        while i < 5:
            if resultat_joueur[i] != '_':
                self.label_resultat_lancer_dict[i] = Label(self.bouton_frame,
                                                           text=self.mettre_en_figure(resultat_joueur[i]))
                self.label_resultat_lancer_dict[i].grid(row=0, column=i, padx=10, pady=10)
            i += 1

    def afficher_boutons(self, nom_joueur):
        """
        Permet d'afficher les boutons
        Args:
            nom_joueur(str): le nom du joueur

        Returns:

        """

        i = 0
        while i < 5:
            index_checkbox = nom_joueur + str(i)
            self.images_des[index_checkbox].grid(self.bouton_frame, row=2, column=i, padx=10, pady=10)
            i += 1

    def evaluer_valeur_combinaison(self, combinaison):
        """
        Permet d'afficher la valeur de la combinaison entre 0 et 7
        Args:
            combinaison(str): nom de la combinaison du joueur

        Returns(int):valeur de la combinaison du joueur

        """

        valeur_combinaison = {'Quinton': 7, 'Carre': 6, 'Full': 5, 'Brelan': 4,
                              'Sequence': 3, 'Deux paires': 2, 'Une paire': 1, 'Autre': 0}
        return valeur_combinaison[str(combinaison)]

    def mettre_en_figure(self, n):
        """
        Affiche la figure (A, R, D, V, X, 9) adéquate pour chaque chiffre (1,..6)
        Args:
            n(int): un chiffre entre 1 et 6

        Returns(str):valeur de n en figure (mot)

        """

        dict = {1: 'A', 2: 'R', 3: 'D', 4: 'V', 5: 'X', 6: '9'}
        return dict[n]

    def passer_au_suivant(self):
        """
        Permet de passer au joueur suivant lorsque le tour du premier joueur est complété
        Établir une limite de lancer pour le prochain joueur
        Déterminer le type de combinaison obtenue
        Ajouter et mettre à jour les données dans le DICTIONNAIRE
        Redonner le contrôle à la fenêtre principale
        Returns:

        """

        # ---- Récupérer les données du DICTIONNAIRE ----
        index_premier_joueur = DICTIONNAIRE["PREMIER_JOUEUR"]
        liste_joueur = DICTIONNAIRE["LISTE_JOUEUR"]

        # ---- Établir une limite de lancer pour le prochain joueur ----
        premier_joueur = liste_joueur[index_premier_joueur]
        if self.nom_joueur == premier_joueur:
            DICTIONNAIRE["LIMITE_LANCER"] = self.num_lancer
        # else:
        #     DICTIONNAIRE["LIMITE_LANCER"] = NB_MAX_LANCERS

        # ---- Déterminer le type de la combinaison ----
        if DICTIONNAIRE["AS_SONT_JOKER"] == True:
            self.combinaison_actuelle = self.determiner_type_combinaison()
        else:
            self.combinaison_actuelle = self.determiner_type_combinaison_sans_as()

        # ---- Ajouter les données au DICTIONNAIRE ----
        DICTIONNAIRE["COMBINAISON{}".format(self.nom_joueur)] = str(self.combinaison_actuelle)
        DICTIONNAIRE['VALEUR_COMBINAISON{}'.format(self.nom_joueur)] = self.evaluer_valeur_combinaison(
            str(self.combinaison_actuelle))

        # ---- Mettre à jour les données dans le DICTIONNAIRE ----
        if DICTIONNAIRE["NB_PARTIE_JOUEES"] > 0:
            self.num_lancer = 0
            DICTIONNAIRE["NUM_LANCER"] = self.num_lancer

        # ---- Redonner le contrôle à la fenêtre principale ----
        self.grab_release()
        self.parent.focus_set()
        self.destroy()

    def afficher_combinaison(self):
        """
        Permet d'afficher le label de la combinaison
        Returns:

        """
        self.label_combinaison['text'] = "Votre combinaison : {}".format(self.combinaison_actuelle)
        self.label_combinaison.grid(row=0, column=0, padx=5, pady=5)

    def cacher_combinaison(self):
        """
        Permet de cacher le label de la combinaison
        Returns:

        """
        self.label_combinaison.grid_forget()

    def empecher_lancer(self):
        """
        Désactive le bouton 'LANCER'
        Returns:

        """
        self.bouton_lancer.config(state=DISABLED)

    def permettre_lancer(self):
        """
        Active le bouton 'LANCER'
        Returns:

        """
        self.bouton_lancer.config(state=NORMAL)

    def empecher_passer(self):
        """
        Désactive le bouton 'PASSER'
        Returns:

        """
        self.bouton_passer.config(state=DISABLED)

    def permettre_passer(self):
        """
        Active le bouton 'PASSER'
        Returns:

        """
        self.bouton_passer.config(state=NORMAL)


# ****************************************************************************


class JoueurInterface(LabelFrame):
    def __init__(self, master, nom, first):
        super().__init__(master, borderwidth=1, relief=RIDGE, )

        self.nom = nom
        self.nb_victoires = 0
        self.nb_partie_jouees = DICTIONNAIRE["NB_PARTIE_JOUEES"]
        self.combinaison_actuelle = None

        self.des_a_relancer = []

        self.resultat_lancer = {}
        self.label_resultat_lancer_dict = {}
        self.resultat_lancer[self.nom] = ['_'] * 5
        resultat_joueur = self.resultat_lancer[self.nom]

        self.nb_lancer = 1
        self.tour = 0

        self.images_des = {}
        self.index_checkbox = []


    def jouer_tour(self, nb_des_a_lancer=NOMBRE_DES_DU_JEU, nb_maximum_lancer=NB_MAX_LANCERS):
        self.nb_des_a_lancer = nb_des_a_lancer
        self.nb_maximum_lancer = nb_maximum_lancer
        self.num_lancer = 0
        self.index_a_relancer = []

    def clear_table(self):
        self.update()

    def asg_tour(self, v):
        self.tour = v


# *****************************************************************************

class InterfaceGraphique(Tk):
    """L'interface Graphique du jeu"""

    TROUVER_PREMIER = 0
    JOUER = 1
    STAT = 2

    def __init__(self):
        super().__init__()
        self.title("Poker As")
        self.geometry("1000x800")
        self.protocol("WM_DELETE_WINDOW", self.confirmation_quitter)

        # ---- Configuration du Menu déroulant ----
        self.menubar = Menu(self)
        menu1 = Menu(self.menubar, tearoff=0)
        menu1.add_command(label="Nouvelle partie", command=self.definir_partie)
        menu1.add_command(label="Règles du jeu", command=self.regles_du_jeu)
        menu1.add_separator()
        menu1.add_command(label="Quitter", command=self.confirmation_quitter)
        self.menubar.add_cascade(label="Menu", menu=menu1)

        self.config(menu=self.menubar)

        # ----- Menu principal -----
        self.title_princ_jeu = Label(self, text="Poker d'as", font=("DejaVu Sans", 26),
                                     width=30, height=3)
        self.title_princ_jeu['background'] = 'green'
        self.bouton_princ_jouer = Button(self, text="Paramètres de la partie", command=self.definir_partie,
                                         width=20, height=2, bg="light green")
        self.bouton_princ_reprendre = Button(self, text="Reprendre", command=self.retablir_donnees_sauvegardees,
                                             width=20, height=2, bg="light blue")
        self.bouton_princ_quitter = Button(self, text="Quitter", command=self.confirmation_quitter,
                                           width=20, height=2, bg="red")

        self.bouton_enregistrer = Button(self, text="Sauvegarder", command=self.enregistrer_partie,
                                         width=20, height=2, bg="pink")

        self.bouton_princ_rejouer = Button(self, text="La revanche ?", command=self.revanche,
                                           width=20, height=2, bg="light blue")

        self.bouton_princ_quitter2 = Button(self, text="Quitter", command=self.confirmation_quitter,
                                            width=20, height=2, bg="red")

        self.title_princ_jeu.grid(row=0, padx=20, pady=10)

        # ----- Élements de la partie -----
        self.frame_de_droit = Frame(self)
        self.frame_de_gauche = Frame(self)
        self.frame_milieu = Frame(self)

        self.recap_canvas = Canvas(self.frame_de_gauche)

        self.boutonframe = Frame(self.frame_de_droit)

        self.phase_label = Label(self.frame_de_droit, text="", font="Arial 12 italic")
        self.message = Label(self.frame_de_droit, text="", font="Arial 14 italic", foreground="blue")

        self.afficher_menu_principal()

    # ----- Gestion de l'affichage -----
    def afficher_menu_principal(self):
        """
        Place les boutons sur le menu principal
        Returns:

        """
        self.title_princ_jeu.place(relx=0.5, rely=0.2, anchor=CENTER)
        self.bouton_princ_jouer.place(relx=0.5, rely=0.6, anchor=CENTER)
        self.bouton_princ_reprendre.place(relx=0.5, rely=0.7, anchor=CENTER)
        self.bouton_princ_quitter.place(relx=0.5, rely=0.8, anchor=CENTER)

    def cacher_menu_principal(self):
        """
        Cache les boutons du Menu principal
        Returns:

        """
        self.title_princ_jeu.place_forget()
        self.bouton_princ_jouer.place_forget()
        self.bouton_princ_reprendre.place_forget()
        self.bouton_princ_quitter.place_forget()

    def afficher_bouton_partie(self):
        """
        Affiche les boutons sur le frame de la partie
        Returns:

        """
        self.bouton_enregistrer.place(relx=0.5, rely=0.6, anchor=CENTER)
        self.bouton_princ_rejouer.place(relx=0.5, rely=0.7, anchor=CENTER)
        self.bouton_princ_quitter2.place(relx=0.5, rely=0.8, anchor=CENTER)

    def cacher_bouton_partie(self):
        """
        Cache les boutons sur le frame de la partie
        Returns:

        """
        self.bouton_enregistrer.place_forget()
        self.bouton_princ_rejouer.place_forget()
        self.bouton_princ_quitter2.place_forget()

    def cacher_partie(self):
        """
        Permet de cacher le frame de la partie
        Returns:

        """
        self.frame_de_gauche.grid_remove()
        self.frame_de_droit.grid_remove()
        self.cacher_bouton_partie()

    def confirmation_quitter(self):
        """
        Envoyer un message de confirmation lorsqu'on ferme la fenêtre principale
        Returns:

        """
        if messagebox.askokcancel("Quitter", "Voulez-vous vraiment quitter?"):
            self.destroy()

    def definir_partie(self):
        """
        Définir les informations des joueurs,
        Afficher la partie,
        Jouer la partie.
        Returns:

        """
        self.indice_joueur_courant = None
        self.phase = InterfaceGraphique.TROUVER_PREMIER
        self.lancer_passer_control_var = BooleanVar(value=False)
        self.choix = None

        # ---- Afficher la fenêtre des options ----
        afficheur_doptions = Parametres_partie(self)
        self.nombre_joueurs, self.as_sont_joker, self.nom_joueurs = afficheur_doptions.get_values_saved()
        self.nb_victoires = 0
        first = True
        self.joueurs = [JoueurInterface(self.frame_de_droit, nom, first) for nom in self.nom_joueurs]
        self.afficher_partie()
        self.jouer()

    def afficher_partie(self):
        """
        Cache la fenêtre du Menu principal
        Affiche les frames d'informations des joueurs
        Affiche le bouton de la partie
        Returns:

        """
        self.cacher_menu_principal()
        self.frame_de_gauche.grid(row=0, column=0)
        self.frame_de_droit.grid(row=0, column=1)
        self.afficher_espace_joueur_courant()
        self.boutonframe.grid(row=3, column=0, columnspan=2)
        self.afficher_bouton_partie()

    def afficher_phase(self):
        """
        Affiche les statistiques du nombres de parties jouées
        Returns:

        """
        self.phase_label.grid_forget()
        if self.phase == InterfaceGraphique.TROUVER_PREMIER:
            self.phase_label['text'] = 'Détermination du premier joueur'
        elif self.phase == InterfaceGraphique.JOUER:
            self.phase_label['text'] = 'On joue....'
        elif self.phase == InterfaceGraphique.STAT:
            liste_joueur = DICTIONNAIRE['LISTE_JOUEUR']
            for joueur in liste_joueur:
                self.phase_label['text'] = 'Nombre de parties jouées : {}'.format(DICTIONNAIRE["NB_PARTIE_JOUEES"])

        self.phase_label.grid(row=0, column=0)

    def afficher_message(self, message):
        """
        Permet d'ajouter le nom du joueur gagnant
        Args:
            message(str): le nom du joueur gagnant

        Returns:

        """
        self.message.grid_forget()
        self.message['text'] = 'Le gagnant de la partie est : {}'.format(message)
        self.message.grid(row=1, columnspan=10, sticky=E)

    def afficher_tableau_recapitulatif(self):
        """
        Afficher les informations de chaque joueurs
        Returns:

        """
        # ---- Vider le Canvas ----
        self.recap_canvas.delete('all')

        # ---- Afficher les canvas avec les informations des joueurs ----
        h, l = 100, 300
        for position, joueur in enumerate(self.joueurs):
            joueur.clear_table()
            nb_victoires = DICTIONNAIRE["NB_VICTOIRE{}".format(joueur.nom)]
            color = "black" if position != self.indice_joueur_courant else "red"
            self.recap_canvas.create_rectangle(1, 1 + (h * position), l, 1 + (h * (position + 1)))
            self.recap_canvas.create_text(15, 25 + (h * position), text=joueur.nom, font="Arial 16 italic", fill=color,
                                          justify="left", anchor=W)
            self.recap_canvas.create_text(50, 70 + (h * position), text=str(nb_victoires) + " victoire(s)",
                                          font="Arial 10 italic", fill=color, justify="left")

            # ---- Ajouter la combinaison au DICTIONNAIRE ----
            combinaison_joueur = DICTIONNAIRE["COMBINAISON{}".format(joueur.nom)]

            comb_str = "Combinaison : {}".format(combinaison_joueur)

            joueur.var_combinaison_actuelle = IntVar()
            joueur.var_combinaison_actuelle.trace('w', self.afficher_tableau_recapitulatif)
            self.recap_canvas.create_text(200, 70 + (h * position), text=comb_str, font="Arial 12 italic",
                                          fill=color, justify="left")

        self.recap_canvas.config(height=(h * int(self.nombre_joueurs) + h), width=l + 50)
        self.recap_canvas.grid(padx=5, pady=5)

        self.recap_canvas.update()

    def afficher_espace_joueur_courant(self, position=None):
        """
        Afficher l'espace du joueur courant
        Args:
            position:

        Returns:

        """
        for joueur in self.joueurs:
            joueur.grid_forget()
        if self.indice_joueur_courant is None:
            self.indice_joueur_courant = 0
        if position is None:
            position = self.indice_joueur_courant
        self.joueurs[position].grid(row=2, column=0, padx=5, pady=5)

    # -----------Deroulement de la partie-------------

    def determiner_ordre(self):
        """
        Déterminer l'ordre des joueurs
        Returns:

        """
        self.ordre = []
        i = 0
        while i < int(self.nombre_joueurs):
            self.ordre += [i]
            i += 1
        shuffle(self.ordre)

        DICTIONNAIRE["PREMIER_JOUEUR"] = self.ordre[0]

    def determiner_premier_lanceur(self):
        """
        Determine le premier lanceur
        Returns:

        """

        self.phase = InterfaceGraphique.TROUVER_PREMIER
        self.afficher_phase()
        self.premier = self.ordre[0]
        self.afficher_tableau_recapitulatif()

    def jouer_tour_premiere_phase(self):
        """
        Joue les tours de tous les joueurs, détermine les joueurs gagnant, affiche les statistiques

        Returns:

        """


        self.phase = InterfaceGraphique.JOUER
        self.afficher_phase()
        for i in range(int(self.nombre_joueurs)):
            self.pos = (self.premier + i) % int(self.nombre_joueurs)
            self.var_pos_joueurs = IntVar()
            self.indice_joueur_courant = self.pos
            self.afficher_espace_joueur_courant(self.pos)
            self.afficher_tableau_recapitulatif()
            nombre_max = DICTIONNAIRE["LIMITE_LANCER"]
            nom_joueur = self.joueurs[self.pos].nom
            tour_joueur = Jouer_tour(self, nom_joueur, nb_des_a_lancer=NOMBRE_DES_DU_JEU, nb_maximum_lancer=nombre_max)
            self.var_pos_joueurs.trace('w', self.joueurs[self.pos].jouer_tour(NOMBRE_DES_DU_JEU))
            self.afficher_tableau_recapitulatif()

        DICTIONNAIRE["NB_PARTIE_JOUEES"] += 1
        self.phase = InterfaceGraphique.STAT
        self.afficher_phase()
        self.determiner_joueur_gagnant()
        self.afficher_message(self.joueur_gagnant)

    def jouer(self):
        """
        Jouer une partie
        Returns:

        """

        self.determiner_ordre()
        self.determiner_premier_lanceur()
        self.jouer_tour_premiere_phase()


    # ---------Gestion des donnees----------

    def enregistrer_partie(self):
        """
        Enregistre tous les éléments de la partie dans un fichier txt
        Ferme la fenêtre de jeu et affiche le menu principal
        Returns:

        """
        enregistrement = ''

        fichier_sauvegarde_dictionnaire = open("test_fichier_sauvegarde.txt", "w")
        for key in DICTIONNAIRE:
            enregistrement += str(key) + ":" + str(DICTIONNAIRE[key]) + "\n"
        fichier_sauvegarde_dictionnaire.write(enregistrement)
        fichier_sauvegarde_dictionnaire.close()
        self.cacher_partie()
        self.afficher_menu_principal()

    def revanche(self):
        """
            Lance une partie avec les mêmes joueurs, et mêmes paramêtres

            """
        self.as_sont_joker = DICTIONNAIRE["AS_SONT_JOKER"]
        self.nombre_joueurs = DICTIONNAIRE["NB_JOUEURS"]
        self.nom_joueurs = DICTIONNAIRE["LISTE_JOUEUR"]

        for joueur in self.nom_joueurs:
            nb_victoire = DICTIONNAIRE["NB_VICTOIRE{}".format(joueur)]
            DICTIONNAIRE["NB_VICTOIRE{}".format(joueur)] = nb_victoire
            DICTIONNAIRE["COMBINAISON{}".format(joueur)] = "autre"

        DICTIONNAIRE["LIMITE_LANCER"] = NB_MAX_LANCERS
        DICTIONNAIRE["NUM_LANCER"] = 0

        self.afficher_partie()
        self.jouer()

    def retablir_donnees_sauvegardees(self):
        """
        Récupère les données sauvegardées dans le DICTIONNAIRE afin de continuer le jeu
        Returns:

        """
        sauvegarde = {}

        fichier_sauvegarde_dictionnaire = open("test_fichier_sauvegarde.txt", "r")
        ligne = fichier_sauvegarde_dictionnaire.readline()
        while ligne != "":
            ligne_epuree = ligne[0:-1]
            liste_ligne = ligne_epuree.split(':')
            sauvegarde[liste_ligne[0]] = liste_ligne[1]
            ligne = fichier_sauvegarde_dictionnaire.readline()
        fichier_sauvegarde_dictionnaire.close()

        self.as_sont_joker = sauvegarde["AS_SONT_JOKER"]

        self.nom_joueurs = sauvegarde["LISTE_JOUEUR"][1:-1]


        nom = ''
        for i in self.nom_joueurs:
            if i == "'":
                i = ""
                nom += i
            elif i == ' ':
                i = ""
                nom += i
            elif i ==',':
                i = ":"
                nom += i
            else:
                nom += i


        self.nom_joueurs = nom.split(":")

        DICTIONNAIRE["LISTE_JOUEUR"] = self.nom_joueurs


        for joueur in self.nom_joueurs:
            DICTIONNAIRE["NB_VICTOIRE{}".format(joueur)] = 0


        for joueur in self.nom_joueurs:
            nb_victoire = int(sauvegarde["NB_VICTOIRE{}".format(joueur)])
            DICTIONNAIRE["NB_VICTOIRE{}".format(joueur)] = nb_victoire
            DICTIONNAIRE["COMBINAISON{}".format(joueur)] = "autre"

        DICTIONNAIRE["LIMITE_LANCER"] = NB_MAX_LANCERS
        DICTIONNAIRE["NUM_LANCER"] = 0
        DICTIONNAIRE["NB_PARTIE_JOUEES"] = int(sauvegarde["NB_PARTIE_JOUEES"])
        self.nombre_joueurs = len(DICTIONNAIRE["LISTE_JOUEUR"])
        DICTIONNAIRE["NB_JOUEURS"] = self.nombre_joueurs


        first = True
        self.indice_joueur_courant = None
        self.joueurs = [JoueurInterface(self.frame_de_droit, nom, first) for nom in self.nom_joueurs]
        self.afficher_partie()
        self.jouer()


    def regles_du_jeu(self):
        """
        Affiche un fichier txt avec les régles du jeu
        Returns:

        """
        webbrowser.open("regles_du_jeu.txt")

    def determiner_joueur_gagnant(self):
        """
        Méthode qui détermine le joueur gagnant parmi une liste.
        Returns :
        """
        meilleure_combinaison = 0
        meilleur_joueur = ['']
        gagnant = ''

        for joueur in DICTIONNAIRE['LISTE_JOUEUR']:
            valeur = DICTIONNAIRE['VALEUR_COMBINAISON{}'.format(joueur)]
            if valeur > meilleure_combinaison:
                meilleure_combinaison = valeur
                meilleur_joueur[0] = joueur
            elif valeur == meilleure_combinaison:
                meilleure_combinaison = 10

        for lettre in meilleur_joueur:
            gagnant += lettre

        if meilleure_combinaison == 10:
            self.joueur_gagnant = 'Partie nulle'
        else:
            DICTIONNAIRE['NB_VICTOIRE{}'.format(gagnant)] += 1
            self.joueur_gagnant = gagnant


# *****************************************************************************
