#!/usr/bin/python

import pygame

class Menuplaymusic:
	
	def __init__( self, path ):
		self.music = pygame.mixer.music.load( path )
		self.counter = 0
		self.fadeC = 0
		self.playC = 0
	
	def play( self ):
		if self.playC == 0:
			self.music = pygame.mixer.music.play( -1, 0.0 )
			self.playC = 1
	
	def pause( self ):
		if self.counter == 0:
			self.music = pygame.mixer.music.pause()
			self.counter = 1
		else:
			self.music = pygame.mixer.music.unpause()
			self.counter = 0
	def fadeOut( self ):
		if self.fadeC == 0:
			self.music = pygame.mixer.music.fadeout( 2000 )

	def stop( self ):
		self.music = pygame.mixer.music.stop()
		
