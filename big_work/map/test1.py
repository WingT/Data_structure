#!/usr/bin/env python
# -*- coding: UTF-8 -*-
from Tkinter import *
class Eay(Frame):
	def createWidgets(self):
		self.draw = Canvas(self, width=500, height=500)
		self.mouse_x = 450
		self.mouse_y = 250
		self.oval_zero_x = 250
		self.oval_zero_y = 250
		self.oval_r = 100
		self.oval_R = 30
		self.oval_r1 = self.oval_r - self.oval_R + 5
		self.oval_r2 = self.oval_r - self.oval_R - 5
		self.letter_ball_x1 = 250
		self.letter_ball_y1 = 250
		self.ball = self.draw.create_oval((self.oval_zero_x - self.oval_r),
			(self.oval_zero_y - self.oval_r),
			(self.oval_zero_x + self.oval_r),
			(self.oval_zero_y + self.oval_r),
			fill="yellow")
		self.ball = self.draw.create_oval((self.oval_zero_x - self.oval_r1),
			(self.oval_zero_y - self.oval_r1),
			(self.oval_zero_x + self.oval_r1),
			(self.oval_zero_y + self.oval_r1),
			fill="blue")
		self.ball = self.draw.create_oval((self.oval_zero_x - self.oval_r2),
			(self.oval_zero_y - self.oval_r2),
			(self.oval_zero_x + self.oval_r2),
			(self.oval_zero_y + self.oval_r2),
			fill="black")
		self.ball_over = self.draw.create_oval((self.oval_zero_x - self.oval_R),
			(self.oval_zero_y - self.oval_R),
			(self.oval_zero_x + self.oval_R),
			(self.oval_zero_y + self.oval_R),
			fill="green")
		self.draw.pack(side=LEFT)
	def mouseMove(self, event):
		self.mouse_x = event.x
		self.mouse_y = event.y
		if SHOW_LOG:
			print('#' * 50)
			print('鼠标的坐标为：({}, {})'.format(self.mouse_x, self.mouse_y))
			print('小圆当前坐标为：({}, {})'.format(self.letter_ball_x1, self.letter_ball_y1))
			'''获取到小圆移动的圆心坐标(x2, y2)'''
		ax_x = abs(self.mouse_x - self.oval_zero_x)
		ax_y = abs(self.mouse_y - self.oval_zero_y)
		if SHOW_LOG:
			print('坐标A(oval_zero_x, oval_zero_y)到坐标X(mouse_x, mouse_y)的距离为AX')
			print('AX中ax_x = {}, ax_y = {}'.format(ax_x, ax_y))
		ax_len = ((ax_x ** 2) + (ax_y ** 2))**0.5
		if SHOW_LOG:
			print('AX的长度为：{}'.format(ax_len))
		if ax_len > abs(self.oval_r - self.oval_R):
			ac_len = abs(self.oval_r - self.oval_R)
			if SHOW_LOG:
				print('AC的产度为:{}'.format(ac_len))
			if int(self.mouse_x - self.oval_zero_x) != 0:
				if int(self.mouse_y - self.oval_zero_y) != 0:
					k = (self.mouse_y - self.oval_zero_y)/(self.mouse_x - self.oval_zero_x)
					if SHOW_LOG:
						print('鼠标到大圆圆心的直线的斜率为：{}'.format(k))
					b = self.mouse_y - (k * self.mouse_x)
					letter_ball_x2 = ((ac_len * (abs(self.mouse_x - self.oval_zero_x)))/ax_len) + self.letter_ball_x1
					letter_ball_y2 = (letter_ball_x2 * k) + b
					if SHOW_LOG:
						print('小圆当前坐标为：({}, {})'.format(self.letter_ball_x1, self.letter_ball_y1))
						print('小圆移动后坐标为：({}, {})'.format(letter_ball_x2, letter_ball_y2))
					self.moved_x2 = letter_ball_x2 - self.letter_ball_x1
					self.moved_y2 = letter_ball_y2 - self.letter_ball_y1
					if SHOW_LOG:
						print('需要移动的距离是：({}, {})'.format(int(self.moved_x2), int(self.moved_y2)))
					self.draw.move(self.ball_over, int(self.moved_x2), int(self.moved_y2))
					self.letter_ball_x1 = letter_ball_x2
					self.letter_ball_y1 = letter_ball_y2
				else:
					print('鼠标在X轴上') 
			else:
				print('鼠标在Y轴上')
		else:
			if SHOW_LOG:
				print('小圆的移动后的坐标就是鼠标坐标')
			letter_ball_x2 = self.mouse_x
			letter_ball_y2 = self.mouse_y
			if SHOW_LOG:
				print('小圆移动后坐标为：({}, {})'.format(letter_ball_x2, letter_ball_y2))
			self.moved_x2 = letter_ball_x2 - self.letter_ball_x1
			self.moved_y2 = letter_ball_y2 - self.letter_ball_y1
			if SHOW_LOG:
				print('需要移动的距离是：({}, {})'.format(int(self.moved_x2), int(self.moved_y2)))
			self.draw.move(self.ball_over, int(self.moved_x2), int(self.moved_y2))
			self.letter_ball_x1 = letter_ball_x2
			self.letter_ball_y1 = letter_ball_y2
	def move_ball(self, *args):
		self.draw.tag_bind(self.ball, "<Any-Enter>", self.mouseMove)
	def __init__(self, master=None):
		global letter_ball_x2
		letter_ball_x2 = 0
		global letter_ball_y2
		letter_ball_y2 = 0
		global SHOW_LOG
		SHOW_LOG = True
		Frame.__init__(self, master)
		Pack.config(self)
		self.createWidgets()
		self.after(1, self.move_ball)
game = Eay()
game.mainloop()
