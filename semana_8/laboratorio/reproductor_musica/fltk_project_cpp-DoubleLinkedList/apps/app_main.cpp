#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include "lista_enlazada.h"

struct AppReproductor {
    Fl_Window* win{nullptr};
    Fl_Box*    lbl{nullptr};
    Fl_Button* btnL{nullptr};
    Fl_Button* btnR{nullptr};
    ListaDoblementeEnlazada songList;

    AppReproductor(int W=520, int H=220, const char* title="FISI-SM (KEPLER GARCIA)") {
        // Datos
        songList.append("Song 1 - Till I Collapse");
        songList.append("Song 2 - Take Me To Church");
        songList.append("Song 3 - 505");
        songList.append("Song 4 - Blinding Lights");
        songList.append("Song 5 - Show Me How to Live");

        // GUI
        win = new Fl_Window(W, H, title);

        lbl = new Fl_Box(20, 40, W-40, 40, "");
        lbl->labelfont(FL_HELVETICA_BOLD);
        lbl->labelsize(20);
        lbl->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

        btnL = new Fl_Button(80,  140, 120, 40, "Left");
        btnR = new Fl_Button(W-80-120, 140, 120, 40, "Right");

        btnL->callback(+[](Fl_Widget*, void* ud){
            auto* self = static_cast<AppReproductor*>(ud);
            self->songList.move_left();
            self->refresh_label();
        }, this);

        btnR->callback(+[](Fl_Widget*, void* ud){
            auto* self = static_cast<AppReproductor*>(ud);
            self->songList.move_right();
            self->refresh_label();
        }, this);

        refresh_label();
        win->end();
    }

    void refresh_label() {
        lbl->copy_label(songList.title_cstr());
        Fl::redraw();
    }

    int run(int argc, char** argv) {
        win->show(argc, argv);
        return Fl::run();
    }
};

int main(int argc, char** argv) {
    AppReproductor app;
    
    return app.run(argc, argv);
}
