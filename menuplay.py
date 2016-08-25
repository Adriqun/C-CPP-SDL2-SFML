#!/usr/bin/python

import pygame
from font import Font
from texture import Texture

class Menuplay:
	
	def __init__( self ):
		self.font = Font( "menu/KGHAPPY.ttf", 80 )
		self.texture = Texture( "menu/blankbutton.png", 4 )
		self.next = 0
		self.click = pygame.mixer.Sound( "menu/click.wav" )
		self.on = 0
	
	def load( self, width, height ):
		self.font.createText( "play", 0x82, 0xae, 0x20 )
		self.font.setX( (width / 2) - (self.font.getWidth() / 2) )
		self.font.setY( (height / 2) - (self.font.getHeight() / 2) - 10 +120 )
		
		self.texture.setX( (width / 2) - (self.texture.getWidth() / 2) )
		self.texture.setY( (height / 2) - (self.texture.getHeight() / 2) +120 )
	
	def draw( self, screen ):
		self.texture.draw( screen )
		self.font.draw( screen )
	
	def fade( self, vel = 1 ):
		self.texture.fade( vel )
		self.font.fade( vel )

	def setState( self ):
		if self.on == 0:
			self.on = 1
		else:
			self.on = 0
		# print self.on
	

	def handle( self, event ):
		self.focus = False
		if event.type == pygame.MOUSEBUTTONDOWN:
			self.focus = True
		
		self.texture.setOffset( 0 )
		self.x, self.y = pygame.mouse.get_pos()
		if self.x > self.texture.getLeft() and self.x < self.texture.getRight():
			if self.y > self.texture.getTop() and self.y < self.texture.getBot():
				if self.focus == True:
					if self.on == 0:
						self.click.play()
					self.texture.setOffset( 2 )
					self.next = 1
				else:
					self.texture.setOffset( 1 )
	def getNext( self ):
		return self.next
	def getLeft( self ):
		return self.texture.getLeft()
	def getBot( self ):
		return self.texture.getBot()
		
