package crotchet;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Keyboard implements KeyListener {

    public boolean[] keys = new boolean[256];

    public Keyboard(Component c) {
        c.addKeyListener(this);
    }

    public boolean isKeyDown(int keyCode) {
        return keys[keyCode];
    }

    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() > 0 && e.getKeyCode() < 256) {
            keys[e.getKeyCode()] = true;
        }
    }

    public void keyReleased(KeyEvent e) {
        if (e.getKeyCode() > 0 && e.getKeyCode() < 256) {
            keys[e.getKeyCode()] = false;
        }
    }

    // unused, but required for implementations of KeyListener
    public void keyTyped(KeyEvent e) {

    }
}

