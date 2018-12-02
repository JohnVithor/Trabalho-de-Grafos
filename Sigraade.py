#!/usr/bin/python3

#import keyboard #Using module keyboard
import sys
import curses
import pandas as pd
import matplotlib.pyplot as plt

turmas_color = pd.read_csv('Turmas/2018.2.color', sep=':', header=None, names=['Disciplina', 'Cor'])
turmas = pd.read_csv('Turmas/2018.2.csv')
max_color = int(turmas_color['Cor'].max()) + 1 # +1 para fazer o múdulo

def gerar_table(cor):
    idxs = turmas_color[turmas_color.Cor == cor]
    idxs['Disciplina'] += 1
    t = turmas.iloc[list(idxs['Disciplina'])]
    d = [di for di in list(t['Componente'])]
    return d
    
def main(win):
    start = 0
    end = 8
    cor = 0
    tab = gerar_table(cor)
    win.nodelay(True)
    key=""
    win.clear()                
    while 1:          
        win.addstr(1,2,'Bem-vindo ao Sigraade, um app pra você')
        win.addstr(2,2,'escolher sua grade de disciplinas do Sigaa')
        win.addstr(3,2,'Pressione "n" para gerar a próxima tabela e')
        win.addstr(4,2,'e os direcionais para navegar nos')
        win.addstr(5,2,'conjuntos de disciplinas')
        win.addstr(6,5,'Conjunto '+ str(cor))
        for i, d in enumerate(tab[start:end]):
            win.addstr(7+i,0,d)
 
        try:                 
           key = win.getkey()         
           win.clear()                
           if key == 'q':
              sys.exit()
           elif key == 'KEY_RIGHT':
               cor = (cor + 1) % max_color
               tab = gerar_table(cor)
               start = 0
               end = 8
           elif key == 'KEY_LEFT':
               cor = (cor - 1) % max_color
               tab = gerar_table(cor)
               start = 0
               end = 8
           elif key == 'KEY_DOWN':
               start = start + 1
               end = end + 1
           elif key == 'KEY_UP':
               start = max(start - 1, 0)
               end = max(end - 1, 8)
        except Exception as e:
           # No input   
           pass         

curses.wrapper(main)
