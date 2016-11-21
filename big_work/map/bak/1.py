#!/usr/bin/env python
INF=0x7fffffff
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

	
	
graph=Graph()
init()
