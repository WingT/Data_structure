#!/usr/bin/env python
from Tkinter import *
import random
INF=0x7fffffff
node_r=20
canvas_width=800
canvas_height=600
edge_disp_ratio=0.1
edge_disp_width=2
node_inactive_color="green"
node_active_color="red"
edge_inactive_color="blue"
edge_active_color="yellow"
edge_tag="edge"
node_tag="node"
class Edge:
	def __init__(self,u,v,leng,intro):
		self.u=u
		self.v=v
		self.leng=leng
		self.intro=intro

class Node:
	def __init__(self,name,intro,vex,freq):
		self.name=name
		self.intro=intro
		self.vex=vex
		self.freq=freq
		self.edges=[]
	
class Graph:
	def __init__(self):
		self.n=0
		self.e=0
		self.node=[]	
		self.edges=[]
		self.dist=[]
		self.path=[]
		self.edges_list=[]
	def floyd(self):
		self.dist=[[INF for i in range(self.n)] for j in range(self.n)]
		self.path=[[-1 for i in range(self.n)] for j in range(self.n)]
		for i in range(self.n):
			for j in range(self.n):
				if self.edges[i][j]<INF:
					self.dist[i][j]=self.edges[i][j]
					self.path[i][j]=i
		for k in range(self.n):
			for i in range(self.n):
				for j in range(self.n):
					if self.dist[i][k]<INF and self.dist[k][j]<INF \
						and self.dist[i][k]+self.dist[k][j]<self.dist[i][j]:
						self.dist[i][j]=self.dist[i][k]+self.dist[k][j]
						self.path[i][j]=self.path[k][j]

def init():
	n=input()
	graph.n=n
	graph.edges=[[INF for col in range(n)] for row in range(n)]
	for i in range(n):
		name=raw_input()
		intro=raw_input()
		freq=input()
		graph.node+=[Node(name,intro,i,freq)]
	e=input()
	graph.e=e
	for i in range(e):
		u=input()
		v=input()
		w=input()
		intro=raw_input()
		new_edge=Edge(u,v,w,intro)
		graph.edges_list.append(new_edge)
		graph.node[u].edges.append(new_edge)
		graph.node[v].edges.append(new_edge)
		if (w<graph.edges[u][v]):
			graph.edges[u][v]=w
			graph.edges[v][u]=w
	for i in range(n):
		graph.edges[i][i]=0

def print_path(i,j):
	if graph.path[i][j]!=j:
		print_path(i,graph.path[i][j])
		print("%d "%(j)),
	else:
		print("%d "%(i)),

def check():
	graph.floyd()
	print('dist')
	for x in graph.dist:
		print(x)
	print('path')
	for i in range(graph.n):
		for j in range(graph.n):
			print("%d %d:%d:"%(i,j,graph.dist[i][j])),
			if graph.dist[i][j]<INF:
				print_path(i,j)
			print('')

	
class Dis_node():
	def __init__(self,canvas,node,x,y):
		self.oval=canvas.create_oval(x-node_r,y-node_r,x+node_r,y+node_r,fill=node_inactive_color,
			activefill=node_active_color)
		self.text=canvas.create_text(x,y,text=node.name)
		self.x=x
		self.y=y

class Dis_edge():
	def __init__(self,canvas,edge,num):
		if num % 2==0:
			ratio=edge_disp_ratio
		else:
			ratio=-edge_disp_ratio
		x1=ui.dis_node[edge.u].x
		y1=ui.dis_node[edge.u].y
		x2=ui.dis_node[edge.v].x
		y2=ui.dis_node[edge.v].y
		if y2==y1:
			x3=(x1+x2)/2.0
			y3=y3+abs(x1-x2)*ratio*(num/2)
		else:
			leng=((x1-x2)**2 + (y1-y2)**2)**0.5
			k=(x1-x2)/(y2-y1+0.0)
			x3=(x1+x2)/2.0 - (1/((1+ k**2)**0.5))*leng*ratio*(num / 2)
			y3=(y1+y2)/2.0 - (k/(1+k**2)**0.5)*leng*ratio*(num/2)
			x3=round(x3)
			y3=round(y3)
		self.line=canvas.create_line(x1,y1,x3,y3,x2,y2,smooth=True,width=edge_disp_width,fill=edge_inactive_color,
			activefill=edge_active_color)

class Ui():
	def __init__(self):
		self.dis_node=[]
		self.dis_edge=[]
	def set_graph(self,graph):
		self.dis_node=[]
		for node in graph.node:
			self.dis_node.append(Dis_node(c,node,random.randint(node_r,canvas_width-node_r),random.randint(node_r,canvas_height-node_r)))
		self.dis_edge=[]
		count=[[0 for col in range(graph.n)] for row in range(graph.n)]
		for edge in graph.edges_list:
			count[edge.u][edge.v]+=1
			count[edge.v][edge.u]+=1
			self.dis_edge.append(Dis_edge(c,edge,count[edge.u][edge.v]))

def edge_enter_handler(event):
	pass	
	
graph=Graph()
init()
graph.floyd()
master=Tk()
c=Canvas(master,width=canvas_width,height=canvas_height)
c.pack()
ui=Ui()
ui.set_graph(graph)
master.mainloop()
