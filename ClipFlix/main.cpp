#include "login.h"
#include <QApplication>

QList<Movie> movie_list();
QList<Serie> serie_list();
QList<Music> music_list();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    l.show();

    User u("demo","demo");
    Data *d = new Data();
    QList<Movie> movies_list = movie_list();
    QList<Serie> series_list = serie_list();
    QList<Music> musics_list = music_list();
    d->add_user(u);
    d->set_movies(movies_list);
    d->set_series(series_list);
    d->set_musics(musics_list);

    l.add_data(d);

    return a.exec();
}

QList<Movie> movie_list(){
    QList<Movie> ret;
    Movie frozen("Frozen 2", 2019, 103, 72, "Anna, Elsa, Kristoff, Olaf and Sven leave Arendelle to travel to an ancient, autumn-bound forest of an enchanted land. They set out to find the origin of Elsa's powers in order to save their kingdom. ");
    QStringList frozen_genre = {"Comedy", "Adventure", "Fantasy", "Animation", "Family", "Musical" };
    QPixmap frozen_image(":/images/image/movie_1.jpg");
    frozen.set_genre(frozen_genre);
    frozen.set_image(frozen_image);
    ret.append(frozen);
    Movie spiderman("Spider-Man: Far from Home", 2019, 129, 81, "Following the events of Vingadores: Endgame (2019), Spider-Man must step up to take on new threats in a world that has changed forever. ");
    QStringList spiderman_genre = {"Action", "Adventure", "Sci-fi"};
    QPixmap spiderman_image(":/images/image/movie_2.jpg");
    spiderman.set_genre(spiderman_genre);
    spiderman.set_image(spiderman_image);
    ret.append(spiderman);
    Movie toy("SOU PORTUGUÊS", 2020, 199, 99, "The great life of the most famous portuguese singer.\
              Since childhood, going through his youth when he started his career \
              until today.");
    QStringList toy_genre = {"Comedy", "Biography"};
    QPixmap toy_image(":/images/image/movie_3.jpg");
    toy.set_genre(toy_genre);
    toy.set_image(toy_image);
    ret.append(toy);

    return ret;
}
QList<Serie> serie_list(){
    QList<Serie> ret;
    //La Casa de Papel
    Serie casapapel("La Casa de Papel");
    casapapel.set_rating(84);
    casapapel.set_seasons(4);
    casapapel.set_finished(false);
    casapapel.set_description("An unusual group of robbers attempt to carry out the most perfect robbery in Spanish history - stealing 2.4 billion euros from the Royal Mint of Spain.");
    casapapel.set_years({2017,2019,2020});
    QStringList casapapel_genre = {"Action", "Crime", "Mystery"};
    casapapel.set_genre(casapapel_genre);
    QPixmap casapapel_image(":/images/image/series_1.jpg");
    casapapel.set_image(casapapel_image);
    ret.append(casapapel);

    //Chernobyl
    Serie chernobyl("Chernobyl");
    chernobyl.set_rating(94);
    chernobyl.set_seasons(1);
    chernobyl.set_finished(true);
    chernobyl.set_description("In April 1986, an explosion at the Chernobyl nuclear power plant in the Union of Soviet Socialist Republics becomes one of the world's worst man-made catastrophes.");
    chernobyl.set_years({2019});
    QStringList chernobyl_genre = {"Drama", "History", "Thriller"};
    chernobyl.set_genre(chernobyl_genre);
    QPixmap chernobyl_image(":/images/image/series_2.jpg");
    chernobyl.set_image(chernobyl_image);
    ret.append(chernobyl);

    //Game of Thrones
    Serie got("Game of Thrones");
    got.set_rating(93);
    got.set_seasons(8);
    got.set_finished(true);
    got.set_description("Nine noble families fight for control over the lands of Westeros, while an ancient enemy returns after being dormant for millennia.");
    got.set_years({2011,2012,2013,2014,2015,2016,2017,2019});
    QStringList got_genre = {"Action", "Adventure", "Drama"};
    got.set_genre(got_genre);
    QPixmap got_image(":/images/image/series_3.jpg");
    got.set_image(got_image);
    ret.append(got);

    //The Witcher
    Serie witcher("The Witcher");
    witcher.set_rating(83);
    witcher.set_seasons(1);
    witcher.set_finished(false);
    witcher.set_description("Geralt of Rivia, a solitary monster hunter, struggles to find his place in a world where people often prove more wicked than beasts.");
    witcher.set_years({2019});
    QStringList witcher_genre = {"Action", "Adventure", "Fantasy"};
    witcher.set_genre(witcher_genre);
    QPixmap witcher_image(":/images/image/series_4.jpg");
    witcher.set_image(witcher_image);
    ret.append(witcher);

    return ret;
}
QList<Music> music_list(){
    QList<Music> ret;

    //Chop Suey!
    Music chop("Chop Suey!", "System of a Down", "Toxicity");
    chop.set_year(2001);
    chop.set_genre("Metal");
    QPixmap chop_image(":/images/image/music_1.jpg");
    chop.set_image(chop_image);
    QTime chop_time(0,3,30);
    chop.set_duration(chop_time);
    ret.append(chop);

    //Gangnam Style
    Music gangnam("Gangnam Style", "PSY", "Psy 6 (Six Rules), Part 1");
    gangnam.set_year(2012);
    gangnam.set_genre("K-POP");
    QPixmap gangnam_image(":/images/image/music_2.jpg");
    gangnam.set_image(gangnam_image);
    QTime gangnam_time(0,3,39);
    gangnam.set_duration(gangnam_time);
    ret.append(gangnam);

    //A Paixão
    Music paixao("A Paixão", "Rui Veloso", "Mingos & Os Samurais");
    paixao.set_year(1990);
    paixao.set_genre("Rock");
    QPixmap paixao_image(":/images/image/music_3.jpg");
    paixao.set_image(paixao_image);
    QTime paixao_time(0,3,50);
    paixao.set_duration(paixao_time);
    ret.append(paixao);

    return ret;
}
