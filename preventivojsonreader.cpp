#include "preventivojsonreader.h"
#include "scuro.h"
#include "finestra.h"
#include "porta.h"
#include "legno.h"
#include "vetro.h"
#include <QByteArray>

PreventivoJsonReader::PreventivoJsonReader(QString s):path(s)
{

}

Preventivo* PreventivoJsonReader::read() const {

    QFile file(path);

    if (!file.open(QIODevice::ReadOnly)) {
        return nullptr;
    } else {

        QByteArray dati_salvati = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(dati_salvati));

        QJsonObject obj = doc.object();
        QString commessa;
        QDate data;
        int numero_articoli = 0;

        if (obj.contains("dati_preventivo")) {
            QJsonObject prev_obj = obj["dati_preventivo"].toObject();
            commessa = prev_obj["commessa"].toString();
            data = QDate::fromJulianDay(prev_obj["data"].toInt());
            numero_articoli = prev_obj["num_articoli"].toInt();
        } else {
            return nullptr;
        }
        //i dati del preventivo erano presenti...
        Preventivo* p = new Preventivo(commessa, data);

        for (int i = 0; i < numero_articoli; i++) {
            QString key = QString::number(i);
            if (obj.contains(key)) {
                QJsonObject art = obj[key].toObject();

                if (art["id"] == "scuro") {
                    Legno::Durezza dur;
                    Scuro::Finiture fin_esterne, fin_interne;

                    switch(art["durezza_legno"].toInt()) {
                        case 0:
                        dur = Legno::Durezza::tenero;
                        break;
                        case 1:
                        dur = Legno::Durezza::duro;
                        break;
                    }

                    switch(art["finiture_esterne"].toInt()) {
                        case 0:
                        fin_esterne = Scuro::Finiture::non_presenti;
                        break;
                        case 1:
                        fin_esterne = Scuro::Finiture::fughe_orizzontali;
                        break;
                        case 2:
                        fin_esterne = Scuro::Finiture::fughe_verticali;
                        break;
                    }

                    switch(art["finiture_interne"].toInt()) {
                        case 0:
                        fin_interne = Scuro::Finiture::non_presenti;
                        break;
                        case 1:
                        fin_interne = Scuro::Finiture::fughe_orizzontali;
                        break;
                        case 2:
                        fin_interne = Scuro::Finiture::fughe_verticali;
                        break;
                    }

                    Scuro* scuro = new Scuro(art["w"].toInt(), art["h"].toInt(), art["prezzo_base"].toDouble(),
                            art["colore_interno"].toString(), art["colore_esterno"].toString(), art["apertura"].toString(),
                            art["coeff_termico_base_legno"].toDouble(), art["prezzo_base_legno"].toDouble(),
                            art["nome_legno"].toString(), dur, art["spazzolatura_legno"].toBool(),
                            art["num_ante"].toInt(), fin_esterne, fin_interne);


                    p->aggiungiArticolo(scuro, art["quantita"].toInt());
                    delete scuro;

                } else if (art["id"] == "porta") {
                    Legno::Durezza dur;

                    switch(art["durezza_legno"].toInt()) {
                        case 0:
                        dur = Legno::Durezza::tenero;
                        break;
                        case 1:
                        dur = Legno::Durezza::duro;
                        break;
                    }

                    Porta::ModoApertura mod_apert;
                    Porta::Serratura tipo_serr;
                    Porta::Cerniera cerniere;

                    switch(art["modo_apertura"].toInt()) {
                        case 0:
                        mod_apert = Porta::ModoApertura::battente;
                        break;
                        case 1:
                        mod_apert = Porta::ModoApertura::scorrevole;
                        break;
                    }

                    switch(art["tipologia_serratura"].toInt()) {
                        case 0:
                        tipo_serr = Porta::Serratura::standard;
                        break;
                        case 1:
                        tipo_serr = Porta::Serratura::magnetica;
                        break;
                        case 2:
                        tipo_serr = Porta::Serratura::non_presente;
                        break;
                    }

                    switch(art["tipologia_cerniera"].toInt()) {
                        case 0:
                        cerniere = Porta::Cerniera::scomparsa;
                        break;
                        case 1:
                        cerniere = Porta::Cerniera::anuba;
                        break;

                    }

                    Porta* porta = new Porta(art["w"].toInt(), art["h"].toInt(), art["prezzo_base"].toDouble(),
                            art["colore_interno"].toString(), art["colore_esterno"].toString(), art["apertura"].toString(),
                            art["coeff_termico_base_legno"].toDouble(), art["prezzo_base_legno"].toDouble(),
                             art["nome_legno"].toString(), dur, art["spazzolatura_legno"].toBool(),
                            art["spessore"].toDouble(), mod_apert, tipo_serr, cerniere);
                    p->aggiungiArticolo(porta, art["quantita"].toInt());

                    delete porta;
                } else if (art["id"] == "finestra") {

                    Legno::Durezza dur;

                    switch(art["durezza_legno"].toInt()) {
                        case 0:
                        dur = Legno::Durezza::tenero;
                        break;
                        case 1:
                        dur = Legno::Durezza::duro;
                        break;
                    }



                    Vetro::Canalina can_vetro;
                    Vetro::Categoria cat_vetro;
                    Vetro::Gas gas_interno;
                    Finestra::ChiusureEsterne chius_est;

                    switch(art["chiusure"].toInt()) {
                        case 0:
                        chius_est = Finestra::ChiusureEsterne::non_presenti;
                        break;
                        case 1:
                        chius_est = Finestra::ChiusureEsterne::tapparelle;
                        break;
                        case 2:
                        chius_est = Finestra::ChiusureEsterne::scuri;
                        break;
                    }

                    switch(art["canalina_vetro"].toInt()) {
                        case 0:
                        can_vetro = Vetro::Canalina::alluminio;
                        break;
                        case 1:
                        can_vetro = Vetro::Canalina::acciaio;
                        break;
                        case 2:
                        can_vetro = Vetro::Canalina::warm_edge;
                        break;
                    }

                    switch(art["categoria_vetro"].toInt()) {
                        case 0:
                        cat_vetro = Vetro::Categoria::temperato;
                        break;
                        case 1:
                        cat_vetro = Vetro::Categoria::stratificato;
                        break;
                        case 2:
                        cat_vetro = Vetro::Categoria::satinato;
                        break;
                    }

                    switch(art["gas_interno_vetro"].toInt()) {
                        case 0:
                        gas_interno = Vetro::Gas::aria;
                        break;
                        case 1:
                        gas_interno = Vetro::Gas::argon;
                        break;
                        case 2:
                        gas_interno = Vetro::Gas::xeno;
                        break;

                    }



                    Finestra* finestra = new Finestra(art["w"].toInt(), art["h"].toInt(), art["prezzo_base"].toDouble(),
                            art["colore_interno"].toString(), art["colore_esterno"].toString(), art["apertura"].toString(),
                            art["coeff_termico_base_legno"].toDouble(), art["prezzo_base_legno"].toDouble(),
                            art["nome_legno"].toString(), dur, art["spazzolatura_legno"].toBool(),
                            art["num_ante"].toInt(), art["spessore_telaio"].toInt(), art["ribalta"].toBool(), chius_est,
                            art["coeff_termico_base_vetro"].toDouble(), art["prezzo_base_vetro"].toDouble(),
                            art["modello_vetro"].toString(), can_vetro, cat_vetro, gas_interno, art["antisfondamento_vetro"].toBool());
                    p->aggiungiArticolo(finestra,art["quantita"].toInt());

                    delete finestra;

                } else {
                    //id sconosciuto
                    delete p;
                    return nullptr;
                }


            } else {
                delete p;
                return nullptr;
            }


        }
        return p;

    }



}

