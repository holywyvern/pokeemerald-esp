#include "global.h"
#include "berry.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_control_avatar.h"
#include "fieldmap.h"
#include "item.h"
#include "item_menu.h"
#include "main.h"
#include "random.h"
#include "string_util.h"
#include "text.h"
#include "constants/event_object_movement.h"
#include "constants/items.h"

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry *enigmaBerry);
static bool32 BerryTreeGrow(struct BerryTree *tree);
static u16 BerryTypeToItemId(u16 berry);
static u8 BerryTreeGetNumStagesWatered(struct BerryTree *tree);
static u8 GetNumStagesWateredByBerryTreeId(u8 id);
static u8 CalcBerryYieldInternal(u16 max, u16 min, u8 water);
static u8 CalcBerryYield(struct BerryTree *tree);
static u8 GetBerryCountByBerryTreeId(u8 id);
static u16 GetStageDurationByBerryType(u8);

//.rodata
static const u8 sBerryDescriptionPart1_Cheri[] = _("Crecen con unas pequeñas flores delicadas.");
static const u8 sBerryDescriptionPart2_Cheri[] = _("Esta baya es roja y muy picante.");
static const u8 sBerryDescriptionPart1_Chesto[] = _("Tanto la piel como la pulpa de esta baya");
static const u8 sBerryDescriptionPart2_Chesto[] = _("es muy dura. Tambíen es muy seca.");
static const u8 sBerryDescriptionPart1_Pecha[] = _("Dulce y deliciosa.");
static const u8 sBerryDescriptionPart2_Pecha[] = _("Tambíen delicada, manejarla con cuidado.");
static const u8 sBerryDescriptionPart1_Rawst[] = _("Si las hojas son largas y curvas,");
static const u8 sBerryDescriptionPart2_Rawst[] = _("esta baya se vuelve muy amarga.");
static const u8 sBerryDescriptionPart1_Aspear[] = _("Esta baya es muy juosa por dentro.");
static const u8 sBerryDescriptionPart2_Aspear[] = _("Tiene un sabor bastante ácido.");
static const u8 sBerryDescriptionPart1_Leppa[] = _("Crece más lento que otras bayas.");
static const u8 sBerryDescriptionPart2_Leppa[] = _("Cuanto más pequeña, mas sabrosa.");
static const u8 sBerryDescriptionPart1_Oran[] = _("Contiene una mezcla de varios sabores.");
static const u8 sBerryDescriptionPart2_Oran[] = _("Tardan medio día en crecer.");
static const u8 sBerryDescriptionPart1_Persim[] = _("Ama la luz solar. Cuando se expone");
static const u8 sBerryDescriptionPart2_Persim[] = _("crece muchísimo.");
static const u8 sBerryDescriptionPart1_Lum[] = _("Crece lentamente. Si se trata con");
static const u8 sBerryDescriptionPart2_Lum[] = _("amor, pueden crecer 2.");
static const u8 sBerryDescriptionPart1_Sitrus[] = _("De la misma familia de Zidra,");
static const u8 sBerryDescriptionPart2_Sitrus[] = _("posee un sabor balanceado.");
static const u8 sBerryDescriptionPart1_Figy[] = _("Cuando se mastica,");
static const u8 sBerryDescriptionPart2_Figy[] = _("libera su sabor picante.");
static const u8 sBerryDescriptionPart1_Wiki[] = _("Se dice que su forma es para");
static const u8 sBerryDescriptionPart2_Wiki[] = _("que los POKéMON la coman.");
static const u8 sBerryDescriptionPart1_Mago[] = _("Se va doblando al crecer.");
static const u8 sBerryDescriptionPart2_Mago[] = _("Cuanto más grande la curva, más dulce.");
static const u8 sBerryDescriptionPart1_Aguav[] = _("Su flor es muy delicada. Crece");
static const u8 sBerryDescriptionPart2_Aguav[] = _("en lugares con poca luz.");
static const u8 sBerryDescriptionPart1_Iapapa[] = _("Es grande y ácida.");
static const u8 sBerryDescriptionPart2_Iapapa[] = _("Tarda hasta un día en crecer.");
static const u8 sBerryDescriptionPart1_Razz[] = _("Es ligeramente picante.");
static const u8 sBerryDescriptionPart2_Razz[] = _("Crece en un par de horas.");
static const u8 sBerryDescriptionPart1_Bluk[] = _("Esta baya es azul por fuera, pero");
static const u8 sBerryDescriptionPart2_Bluk[] = _("tiñe de negro la boca de quien la come.");
static const u8 sBerryDescriptionPart1_Nanab[] = _("Fue la séptima baya descubierta");
static const u8 sBerryDescriptionPart2_Nanab[] = _("en el mundo. Es muy dulce.");
static const u8 sBerryDescriptionPart1_Wepear[] = _("Su flor es blanca y pequeña. Tiene");
static const u8 sBerryDescriptionPart2_Wepear[] = _("un balance entre amargo y ácido.");
static const u8 sBerryDescriptionPart1_Pinap[] = _("No resiste el frío o viento.");
static const u8 sBerryDescriptionPart2_Pinap[] = _("Tiene una piel ácida.");
static const u8 sBerryDescriptionPart1_Pomeg[] = _("Sin importar cuanto se riegue,");
static const u8 sBerryDescriptionPart2_Pomeg[] = _("solo crecerán hasta 6 bayas.");
static const u8 sBerryDescriptionPart1_Kelpsy[] = _("Parece una raiz.");
static const u8 sBerryDescriptionPart2_Kelpsy[] = _("Tiene una flor muy grande.");
static const u8 sBerryDescriptionPart1_Qualot[] = _("Ama el agua. Crece mejor en");
static const u8 sBerryDescriptionPart2_Qualot[] = _("climas húmedos.");
static const u8 sBerryDescriptionPart1_Hondew[] = _("Una baya muy valiosa y rara");
static const u8 sBerryDescriptionPart2_Hondew[] = _("vez vista. Es muy deliciosa.");
static const u8 sBerryDescriptionPart1_Grepa[] = _("A pesar de ser suave y redonda");
static const u8 sBerryDescriptionPart2_Grepa[] = _("es sorprendentemente ácida.");
static const u8 sBerryDescriptionPart1_Tamato[] = _("Está baya es muy picante.");
static const u8 sBerryDescriptionPart2_Tamato[] = _("Se toma su tiempo en crecer.");
static const u8 sBerryDescriptionPart1_Cornn[] = _("Proviene de una era antigua. Quizás");
static const u8 sBerryDescriptionPart2_Cornn[] = _("no crezca si no se planta en cantidad.");
static const u8 sBerryDescriptionPart1_Magost[] = _("Una baya popularmente conocida por");
static const u8 sBerryDescriptionPart2_Magost[] = _("su sabor balanceado.");
static const u8 sBerryDescriptionPart1_Rabuta[] = _("Una baya rara cubierta de");
static const u8 sBerryDescriptionPart2_Rabuta[] = _("pelos. Es muy amarga.");
static const u8 sBerryDescriptionPart1_Nomel[] = _("Bastante ácida. Solo un bocado hace");
static const u8 sBerryDescriptionPart2_Nomel[] = _("perdér el gusto por tres días.");
static const u8 sBerryDescriptionPart1_Spelon[] = _("Rojo brillante y muy picante.");
static const u8 sBerryDescriptionPart2_Spelon[] = _("Sus jugos arden al tacto.");
static const u8 sBerryDescriptionPart1_Pamtre[] = _("Viaja por el mar descuidadamente.");
static const u8 sBerryDescriptionPart2_Pamtre[] = _("Se dice que crece en otro lado.");
static const u8 sBerryDescriptionPart1_Watmel[] = _("Una baya gigante, se descubrió una");
static const u8 sBerryDescriptionPart2_Watmel[] = _("de 80cm. Es muy dulce.");
static const u8 sBerryDescriptionPart1_Durin[] = _("Amarga a la vista. Es tan amarga");
static const u8 sBerryDescriptionPart2_Durin[] = _("que nadie puede comerla sin preparación.");
static const u8 sBerryDescriptionPart1_Belue[] = _("Es brillante y se ve deliciosa, pero");
static const u8 sBerryDescriptionPart2_Belue[] = _("es extremadamente ácida. Tarda en crecer.");
static const u8 sBerryDescriptionPart1_Liechi[] = _("Se rumorea que esta baya contiene");
static const u8 sBerryDescriptionPart2_Liechi[] = _("el poder del mar.");
static const u8 sBerryDescriptionPart1_Ganlon[] = _("Se rumorea que esta baya contiene");
static const u8 sBerryDescriptionPart2_Ganlon[] = _("el poder de la tierra.");
static const u8 sBerryDescriptionPart1_Salac[] = _("Se rumorea que esta baya contiene");
static const u8 sBerryDescriptionPart2_Salac[] = _("el poder del cielo.");
static const u8 sBerryDescriptionPart1_Petaya[] = _("Se rumorea que esta baya contiene");
static const u8 sBerryDescriptionPart2_Petaya[] = _("el poder de todos los seres vivos.");
static const u8 sBerryDescriptionPart1_Apicot[] = _("Una baya muy misteriosa");
static const u8 sBerryDescriptionPart2_Apicot[] = _("nadie sabe como se usa.");
static const u8 sBerryDescriptionPart1_Lansat[] = _("Una baya legendaria.");
static const u8 sBerryDescriptionPart2_Lansat[] = _("Se dice que sostenerla da alegría.");
static const u8 sBerryDescriptionPart1_Starf[] = _("Tan poderosa que fue dejada en el");
static const u8 sBerryDescriptionPart2_Starf[] = _("fin del mundo. Se cree una ilusión.");
static const u8 sBerryDescriptionPart1_Enigma[] = _("Completamente misteriosa.");
static const u8 sBerryDescriptionPart2_Enigma[] = _("Se dice tener el poder de los cielos.");

static const u8 sBerryDescriptionPart1_Occa[] = _("Crece en climas cálidos,");
static const u8 sBerryDescriptionPart2_Occa[] = _("es intensamente picante.");
static const u8 sBerryDescriptionPart1_Passho[] = _("Su piel contiene muchísimas burbujas");
static const u8 sBerryDescriptionPart2_Passho[] = _("que la mantiene a flote en el agua.");
static const u8 sBerryDescriptionPart1_Wacan[] = _("Obtiene energía de las tormentas");
static const u8 sBerryDescriptionPart2_Wacan[] = _("eléctricas para crecer grande y fuerte.");
static const u8 sBerryDescriptionPart1_Rindo[] = _("Esta baya sabe a un vegetal,");
static const u8 sBerryDescriptionPart2_Rindo[] = _("al contener mucha fibra nutritiva.");
static const u8 sBerryDescriptionPart1_Yache[] = _("Tiene un sabor refrescantemente");
static const u8 sBerryDescriptionPart2_Yache[] = _("ácido y seco. Es mejor fría.");
static const u8 sBerryDescriptionPart1_Chople[] = _("Una substancia dentro genera calor.");
static const u8 sBerryDescriptionPart2_Chople[] = _("Calienta el corazón de quien la consume.");
static const u8 sBerryDescriptionPart1_Kebia[] = _("Verde brillante por fuera,");
static const u8 sBerryDescriptionPart2_Kebia[] = _("tiene una pulpa negra por dentro.");
static const u8 sBerryDescriptionPart1_Shuca[] = _("La pupa es dulce, y");
static const u8 sBerryDescriptionPart2_Shuca[] = _("tiene tonos duros en la cáscara.");
static const u8 sBerryDescriptionPart1_Coba[] = _("Se dice que es una cruza de");
static const u8 sBerryDescriptionPart2_Coba[] = _("dos bayas crecicas lejos de aqui.");
static const u8 sBerryDescriptionPart1_Payapa[] = _("Dicen que siente emociones humanas,");
static const u8 sBerryDescriptionPart2_Payapa[] = _("sieñe agitarse cuando alguien se acerca.");
static const u8 sBerryDescriptionPart1_Tanga[] = _("Crece una flor en la punta que atrae");
static const u8 sBerryDescriptionPart2_Tanga[] = _("Pokémon bicho a sus pétalos.");
static const u8 sBerryDescriptionPart1_Charti[] = _("Utilizada comunmente para vinagretas");
static const u8 sBerryDescriptionPart2_Charti[] = _("por su sabor seco. A veces se come cruda.");
static const u8 sBerryDescriptionPart1_Kasib[] = _("Las supersticiones dicen que contiene un");
static const u8 sBerryDescriptionPart2_Kasib[] = _("gran poder. Usada como amuleto de la suerte.");
static const u8 sBerryDescriptionPart1_Haban[] = _("Su sabor amargo no es tan fuerte si se");
static const u8 sBerryDescriptionPart2_Haban[] = _("hierve. Hace una mermelada sabrosa.");
static const u8 sBerryDescriptionPart1_Colbur[] = _("Pequeños pinchos en la baya se adhieren a");
static const u8 sBerryDescriptionPart2_Colbur[] = _("los Pokémon para llegar a lugares lejanos.");
static const u8 sBerryDescriptionPart1_Babiri[] = _("De un sabor intenso. Fue utilizada");
static const u8 sBerryDescriptionPart2_Babiri[] = _("para crear medicamentos en el pasado.");
static const u8 sBerryDescriptionPart1_Chilan[] = _("Con esta baya se puede crear un");
static const u8 sBerryDescriptionPart2_Chilan[] = _("silbato de un sonido indescriptible.");
static const u8 sBerryDescriptionPart1_Roseli[] = _("En la naturaleza crece en círculos,");
static const u8 sBerryDescriptionPart2_Roseli[] = _("por motivos que aún se desconocen.");

const struct Berry gBerries[] =
{
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Zreza"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 20,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Cheri,
        .description2 = sBerryDescriptionPart2_Cheri,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Atania"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 80,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Chesto,
        .description2 = sBerryDescriptionPart2_Chesto,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Meloc"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 40,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Pecha,
        .description2 = sBerryDescriptionPart2_Pecha,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Safre"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 32,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Rawst,
        .description2 = sBerryDescriptionPart2_Rawst,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Perasi"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 50,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Aspear,
        .description2 = sBerryDescriptionPart2_Aspear,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },

    [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Zanama"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 28,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Leppa,
        .description2 = sBerryDescriptionPart2_Leppa,
        .stageDuration = 4,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Aranja"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 35,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Oran,
        .description2 = sBerryDescriptionPart2_Oran,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Caquic"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 47,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Persim,
        .description2 = sBerryDescriptionPart2_Persim,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_LUM_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Ziuela"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 34,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Lum,
        .description2 = sBerryDescriptionPart2_Lum,
        .stageDuration = 12,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Zidra"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Sitrus,
        .description2 = sBerryDescriptionPart2_Sitrus,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Higog"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 100,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Figy,
        .description2 = sBerryDescriptionPart2_Figy,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Wiki"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 115,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Wiki,
        .description2 = sBerryDescriptionPart2_Wiki,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Ango"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 126,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Mago,
        .description2 = sBerryDescriptionPart2_Mago,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Guaya"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 64,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Aguav,
        .description2 = sBerryDescriptionPart2_Aguav,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Pabaya"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 223,
        .maxYield = 30,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Iapapa,
        .description2 = sBerryDescriptionPart2_Iapapa,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },

    [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Frambu"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 120,
        .maxYield = 60,
        .minYield = 30,
        .description1 = sBerryDescriptionPart1_Razz,
        .description2 = sBerryDescriptionPart2_Razz,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Oram"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 108,
        .maxYield = 60,
        .minYield = 30,
        .description1 = sBerryDescriptionPart1_Bluk,
        .description2 = sBerryDescriptionPart2_Bluk,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Latano"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 77,
        .maxYield = 60,
        .minYield = 30,
        .description1 = sBerryDescriptionPart1_Nanab,
        .description2 = sBerryDescriptionPart2_Nanab,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Peragu"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 74,
        .maxYield = 60,
        .minYield = 30,
        .description1 = sBerryDescriptionPart1_Wepear,
        .description2 = sBerryDescriptionPart2_Wepear,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Pinia"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 80,
        .maxYield = 60,
        .minYield = 30,
        .description1 = sBerryDescriptionPart1_Pinap,
        .description2 = sBerryDescriptionPart2_Pinap,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Grana"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 135,
        .maxYield = 60,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Pomeg,
        .description2 = sBerryDescriptionPart2_Pomeg,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Algama"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 150,
        .maxYield = 60,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Kelpsy,
        .description2 = sBerryDescriptionPart2_Kelpsy,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Ispero"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 110,
        .maxYield = 60,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Qualot,
        .description2 = sBerryDescriptionPart2_Qualot,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Meluce"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 162,
        .maxYield = 60,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Hondew,
        .description2 = sBerryDescriptionPart2_Hondew,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Uvav"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 149,
        .maxYield = 60,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Grepa,
        .description2 = sBerryDescriptionPart2_Grepa,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Tamate"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 200,
        .maxYield = 40,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Tamato,
        .description2 = sBerryDescriptionPart2_Tamato,
        .stageDuration = 6,
        .spicy = 20,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Mais"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 40,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Cornn,
        .description2 = sBerryDescriptionPart2_Cornn,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 20,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Aostan"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 140,
        .maxYield = 40,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Magost,
        .description2 = sBerryDescriptionPart2_Magost,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 20,
        .bitter = 10,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Rautan"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 226,
        .maxYield = 40,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Rabuta,
        .description2 = sBerryDescriptionPart2_Rabuta,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 20,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Monli"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 285,
        .maxYield = 40,
        .minYield = 20,
        .description1 = sBerryDescriptionPart1_Nomel,
        .description2 = sBerryDescriptionPart2_Nomel,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 20,
        .smoothness = 30,
    },

    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Wikano"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 133,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Spelon,
        .description2 = sBerryDescriptionPart2_Spelon,
        .stageDuration = 18,
        .spicy = 40,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Plama"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 244,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Pamtre,
        .description2 = sBerryDescriptionPart2_Pamtre,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 40,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Sambia"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 250,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Watmel,
        .description2 = sBerryDescriptionPart2_Watmel,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 10,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Rudion"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 280,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Durin,
        .description2 = sBerryDescriptionPart2_Durin,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 10,
        .smoothness = 70,
    },

    [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Andano"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 300,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Belue,
        .description2 = sBerryDescriptionPart2_Belue,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Lichi"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 111,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Liechi,
        .description2 = sBerryDescriptionPart2_Liechi,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 10,
        .smoothness = 80,
    },

    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Gonlan"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 33,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Ganlon,
        .description2 = sBerryDescriptionPart2_Ganlon,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },

    [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Aslac"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Salac,
        .description2 = sBerryDescriptionPart2_Salac,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },

    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Yapati"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 237,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Petaya,
        .description2 = sBerryDescriptionPart2_Petaya,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },

    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Aricot"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Apicot,
        .description2 = sBerryDescriptionPart2_Apicot,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },

    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Zonlan"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 97,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Lansat,
        .description2 = sBerryDescriptionPart2_Lansat,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_STARF_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Arabol"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 153,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Starf,
        .description2 = sBerryDescriptionPart2_Starf,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Enigma"),
        .firmness = BERRY_FIRMNESS_UNKNOWN,
        .size = 0,
        .maxYield = 20,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Enigma,
        .description2 = sBerryDescriptionPart2_Enigma,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 40,
        .sweet = 40,
        .bitter = 40,
        .sour = 40,
        .smoothness = 40,
    },

    [ITEM_OCCA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Caoca"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 89,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Occa,
        .description2 = sBerryDescriptionPart2_Occa,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_PASSHO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Pasio"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 33,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Passho,
        .description2 = sBerryDescriptionPart2_Passho,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_WACAN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Gualot"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 250,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Wacan,
        .description2 = sBerryDescriptionPart2_Wacan,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_RINDO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Tamar"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 155,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Rindo,
        .description2 = sBerryDescriptionPart2_Rindo,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_YACHE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Rimoya"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 135,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Yache,
        .description2 = sBerryDescriptionPart2_Yache,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_CHOPLE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Pomaro"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 77,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Chople,
        .description2 = sBerryDescriptionPart2_Chople,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_KEBIA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Kebia"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 89,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Kebia,
        .description2 = sBerryDescriptionPart2_Kebia,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_SHUCA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Acardo"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 42,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Shuca,
        .description2 = sBerryDescriptionPart2_Shuca,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_COBA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Kouba"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 277,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Coba,
        .description2 = sBerryDescriptionPart2_Coba,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_PAYAPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Payapa"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 251,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Payapa,
        .description2 = sBerryDescriptionPart2_Payapa,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_TANGA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Yecana"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 43,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Tanga,
        .description2 = sBerryDescriptionPart2_Tanga,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_CHARTI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Alcho"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 28,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Charti,
        .description2 = sBerryDescriptionPart2_Charti,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_KASIB_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Drasi"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 144,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Kasib,
        .description2 = sBerryDescriptionPart2_Kasib,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_HABAN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Anjiro"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 23,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Haban,
        .description2 = sBerryDescriptionPart2_Haban,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_COLBUR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Dillo"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 38,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Colbur,
        .description2 = sBerryDescriptionPart2_Colbur,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_BABIRI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Baribá"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 265,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Babiri,
        .description2 = sBerryDescriptionPart2_Babiri,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_CHILAN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Chilan"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 33,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Chilan,
        .description2 = sBerryDescriptionPart2_Chilan,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_ROSELI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Roseli"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 35,
        .maxYield = 50,
        .minYield = 10,
        .description1 = sBerryDescriptionPart1_Roseli,
        .description2 = sBerryDescriptionPart2_Roseli,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },
};

const struct BerryCrushBerryData gBerryCrush_BerryData[] = {
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  20},
    [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  20},
    [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  30},
    [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  50, .powder =  30},
    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  30},
    [ITEM_LUM_BERRY - FIRST_BERRY_INDEX]    = {.difficulty =  50, .powder =  30},
    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  30},
    [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  60, .powder =  50},
    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  60, .powder =  50},
    [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  80, .powder =  70},
    [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  80, .powder =  70},
    [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  80, .powder =  70},
    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  80, .powder =  70},
    [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  80, .powder =  70},
    [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 100, .powder = 100},
    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 100, .powder = 100},
    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 130, .powder = 150},
    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 130, .powder = 150},
    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 160, .powder = 250},
    [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 160, .powder = 250},
    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 180, .powder = 500},
    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 200, .powder = 750},
    [ITEM_STARF_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 200, .powder = 750},
    [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 150, .powder = 200}
};

const struct BerryTree gBlankBerryTree = {};

// unused
void ClearEnigmaBerries(void)
{
    CpuFill16(0, &gSaveBlock1Ptr->enigmaBerry, sizeof(gSaveBlock1Ptr->enigmaBerry));
}

void SetEnigmaBerry(u8 *src)
{
    u32 i;
    u8 *dest = (u8*)&gSaveBlock1Ptr->enigmaBerry;

    for (i = 0; i < sizeof(gSaveBlock1Ptr->enigmaBerry); i++)
        dest[i] = src[i];
}

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry *enigmaBerry)
{
    u32 i;
    u32 checksum;
    u8 *dest;

    dest = (u8*)enigmaBerry;
    checksum = 0;
    for (i = 0; i < sizeof(gSaveBlock1Ptr->enigmaBerry) - sizeof(gSaveBlock1Ptr->enigmaBerry.checksum); i++)
        checksum += dest[i];

    return checksum;
}

bool32 IsEnigmaBerryValid(void)
{
    if (!gSaveBlock1Ptr->enigmaBerry.berry.stageDuration)
        return FALSE;
    if (!gSaveBlock1Ptr->enigmaBerry.berry.maxYield)
        return FALSE;
    if (GetEnigmaBerryChecksum(&gSaveBlock1Ptr->enigmaBerry) != gSaveBlock1Ptr->enigmaBerry.checksum)
        return FALSE;
    return TRUE;
}

const struct Berry *GetBerryInfo(u8 berry)
{
    if (berry == ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) && IsEnigmaBerryValid())
        return (struct Berry*)(&gSaveBlock1Ptr->enigmaBerry.berry);
    else
    {
        if (berry == BERRY_NONE || berry > ITEM_TO_BERRY(LAST_BERRY_INDEX))
            berry = ITEM_TO_BERRY(FIRST_BERRY_INDEX);
        return &gBerries[berry - 1];
    }
}

struct BerryTree *GetBerryTreeInfo(u8 id)
{
    return &gSaveBlock1Ptr->berryTrees[id];
}

bool32 ObjectEventInteractionWaterBerryTree(void)
{
    struct BerryTree *tree = GetBerryTreeInfo(GetObjectEventBerryTreeId(gSelectedObjectEvent));

    switch (tree->stage)
    {
    case BERRY_STAGE_PLANTED:
        tree->watered1 = TRUE;
        break;
    case BERRY_STAGE_SPROUTED:
        tree->watered2 = TRUE;
        break;
    case BERRY_STAGE_TALLER:
        tree->watered3 = TRUE;
        break;
    case BERRY_STAGE_FLOWERING:
        tree->watered4 = TRUE;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

bool8 IsPlayerFacingEmptyBerryTreePatch(void)
{
    if (GetObjectEventScriptPointerPlayerFacing() == BerryTreeScript
     && GetStageByBerryTreeId(GetObjectEventBerryTreeId(gSelectedObjectEvent)) == BERRY_STAGE_NO_BERRY)
        return TRUE;
    else
        return FALSE;
}

bool8 TryToWaterBerryTree(void)
{
    if (GetObjectEventScriptPointerPlayerFacing() != BerryTreeScript)
        return FALSE;
    else
        return ObjectEventInteractionWaterBerryTree();
}

void ClearBerryTrees(void)
{
    int i;

    for (i = 0; i < BERRY_TREES_COUNT; i++)
        gSaveBlock1Ptr->berryTrees[i] = gBlankBerryTree;
}

static bool32 BerryTreeGrow(struct BerryTree *tree)
{
    if (tree->stopGrowth)
        return FALSE;

    switch (tree->stage)
    {
    case BERRY_STAGE_NO_BERRY:
        return FALSE;
    case BERRY_STAGE_FLOWERING:
        tree->berryYield = CalcBerryYield(tree);
    case BERRY_STAGE_PLANTED:
    case BERRY_STAGE_SPROUTED:
    case BERRY_STAGE_TALLER:
        tree->stage++;
        break;
    case BERRY_STAGE_BERRIES:
        tree->watered1 = 0;
        tree->watered2 = 0;
        tree->watered3 = 0;
        tree->watered4 = 0;
        tree->berryYield = 0;
        tree->stage = BERRY_STAGE_SPROUTED;
        if (++tree->regrowthCount == 10)
            *tree = gBlankBerryTree;
        break;
    }
    return TRUE;
}

void BerryTreeTimeUpdate(s32 minutes)
{
    int i;
    struct BerryTree *tree;

    for (i = 0; i < BERRY_TREES_COUNT; i++)
    {
        tree = &gSaveBlock1Ptr->berryTrees[i];

        if (tree->berry && tree->stage && !tree->stopGrowth)
        {
            if (minutes >= GetStageDurationByBerryType(tree->berry) * 71)
            {
                *tree = gBlankBerryTree;
            }
            else
            {
                s32 time = minutes;

                while (time != 0)
                {
                    if (tree->minutesUntilNextStage > time)
                    {
                        tree->minutesUntilNextStage -= time;
                        break;
                    }
                    time -= tree->minutesUntilNextStage;
                    tree->minutesUntilNextStage = GetStageDurationByBerryType(tree->berry);
                    if (!BerryTreeGrow(tree))
                        break;
                    if (tree->stage == BERRY_STAGE_BERRIES)
                        tree->minutesUntilNextStage *= 4;
                }
            }
        }
    }
}

void PlantBerryTree(u8 id, u8 berry, u8 stage, bool8 allowGrowth)
{
    struct BerryTree *tree = GetBerryTreeInfo(id);

    *tree = gBlankBerryTree;
    tree->berry = berry;
    tree->minutesUntilNextStage = GetStageDurationByBerryType(berry);
    tree->stage = stage;
    if (stage == BERRY_STAGE_BERRIES)
    {
        tree->berryYield = CalcBerryYield(tree);
        tree->minutesUntilNextStage *= 4;
    }

    // Stop growth, to keep tree at this stage until the player has seen it
    // allowGrowth is always true for berry trees the player has planted
    if (!allowGrowth)
        tree->stopGrowth = TRUE;
}

void RemoveBerryTree(u8 id)
{
    gSaveBlock1Ptr->berryTrees[id] = gBlankBerryTree;
}

u8 GetBerryTypeByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].berry;
}

u8 GetStageByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].stage;
}

u8 ItemIdToBerryType(u16 item)
{
    u16 berry = item - FIRST_BERRY_INDEX;

    if (berry > LAST_BERRY_INDEX - FIRST_BERRY_INDEX)
        return ITEM_TO_BERRY(FIRST_BERRY_INDEX);
    else
        return ITEM_TO_BERRY(item);
}

static u16 BerryTypeToItemId(u16 berry)
{
    u16 item = berry - 1;

    if (item > LAST_BERRY_INDEX - FIRST_BERRY_INDEX)
        return FIRST_BERRY_INDEX;
    else
        return berry + FIRST_BERRY_INDEX - 1;
}

void GetBerryNameByBerryType(u8 berry, u8 *string)
{
    memcpy(string, GetBerryInfo(berry)->name, BERRY_NAME_LENGTH);
    string[BERRY_NAME_LENGTH] = EOS;
}

void GetBerryCountStringByBerryType(u8 berry, u8* dest, u32 berryCount)
{
    GetBerryCountString(dest, GetBerryInfo(berry)->name, berryCount);
}

void AllowBerryTreeGrowth(u8 id)
{
    GetBerryTreeInfo(id)->stopGrowth = FALSE;
}

static u8 BerryTreeGetNumStagesWatered(struct BerryTree *tree)
{
    u8 count = 0;

    if (tree->watered1)
        count++;
    if (tree->watered2)
        count++;
    if (tree->watered3)
        count++;
    if (tree->watered4)
        count++;
    return count;
}

static u8 GetNumStagesWateredByBerryTreeId(u8 id)
{
    return BerryTreeGetNumStagesWatered(GetBerryTreeInfo(id));
}

// Berries can be watered at 4 stages of growth. This function is likely meant
// to divide the berry yield range equally into quartiles. If you watered the
// tree n times, your yield is a random number in the nth quartile.
//
// However, this function actually skews towards higher berry yields, because
// it rounds `extraYield` to the nearest whole number.
//
// See resulting yields: https://gist.github.com/hondew/2a099dbe54aa91414decdbfaa524327d,
// and bug fix: https://gist.github.com/hondew/0f0164e5b9dadfd72d24f30f2c049a0b.
static u8 CalcBerryYieldInternal(u16 max, u16 min, u8 water)
{
    u32 randMin;
    u32 randMax;
    u32 rand;
    u32 extraYield;

    if (water == 0)
        return min;
    else
    {
        randMin = (max - min) * (water - 1);
        randMax = (max - min) * (water);
        rand = randMin + Random() % (randMax - randMin + 1);

        // Round upwards
        if ((rand % NUM_WATER_STAGES) >= NUM_WATER_STAGES / 2)
            extraYield = rand / NUM_WATER_STAGES + 1;
        else
            extraYield = rand / NUM_WATER_STAGES;
        return extraYield + min;
    }
}

static u8 CalcBerryYield(struct BerryTree *tree)
{
    const struct Berry *berry = GetBerryInfo(tree->berry);
    u8 min = berry->minYield;
    u8 max = berry->maxYield;

    return CalcBerryYieldInternal(max, min, BerryTreeGetNumStagesWatered(tree));
}

static u8 GetBerryCountByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].berryYield;
}

static u16 GetStageDurationByBerryType(u8 berry)
{
    return GetBerryInfo(berry)->stageDuration * 60;
}

void ObjectEventInteractionGetBerryTreeData(void)
{
    u8 id;
    u8 berry;
    u8 localId;
    u8 group;
    u8 num;

    id = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    berry = GetBerryTypeByBerryTreeId(id);
    AllowBerryTreeGrowth(id);
    localId = gSpecialVar_LastTalked;
    num = gSaveBlock1Ptr->location.mapNum;
    group = gSaveBlock1Ptr->location.mapGroup;
    if (IsBerryTreeSparkling(localId, num, group))
        gSpecialVar_0x8004 = BERRY_STAGE_SPARKLING;
    else
        gSpecialVar_0x8004 = GetStageByBerryTreeId(id);
    gSpecialVar_0x8005 = GetNumStagesWateredByBerryTreeId(id);
    gSpecialVar_0x8006 = GetBerryCountByBerryTreeId(id);
    GetBerryCountStringByBerryType(berry, gStringVar1, gSpecialVar_0x8006);
}

void ObjectEventInteractionGetBerryName(void)
{
    u8 berryType = GetBerryTypeByBerryTreeId(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    GetBerryNameByBerryType(berryType, gStringVar1);
}

void ObjectEventInteractionGetBerryCountString(void)
{
    u8 treeId = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    u8 berry = GetBerryTypeByBerryTreeId(treeId);
    u8 count = GetBerryCountByBerryTreeId(treeId);
    GetBerryCountStringByBerryType(berry, gStringVar1, count);
}

void Bag_ChooseBerry(void)
{
    SetMainCallback2(CB2_ChooseBerry);
}

void ObjectEventInteractionPlantBerryTree(void)
{
    u8 berry = ItemIdToBerryType(gSpecialVar_ItemId);

    PlantBerryTree(GetObjectEventBerryTreeId(gSelectedObjectEvent), berry, 1, TRUE);
    ObjectEventInteractionGetBerryTreeData();
}

void ObjectEventInteractionPickBerryTree(void)
{
    u8 id = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    u8 berry = GetBerryTypeByBerryTreeId(id);

    gSpecialVar_0x8004 = AddBagItem(BerryTypeToItemId(berry), GetBerryCountByBerryTreeId(id));
}

void ObjectEventInteractionRemoveBerryTree(void)
{
    RemoveBerryTree(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    SetBerryTreeJustPicked(gSpecialVar_LastTalked, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

bool8 PlayerHasBerries(void)
{
    return IsBagPocketNonEmpty(POCKET_BERRIES);
}

// Berry tree growth is frozen at their initial stage (usually, fully grown) until the player has seen the tree
// For all berry trees on screen, allow normal growth
void SetBerryTreesSeen(void)
{
    s16 cam_left;
    s16 cam_top;
    s16 left;
    s16 top;
    s16 right;
    s16 bottom;
    int i;

    GetCameraCoords(&cam_left, &cam_top);
    left = cam_left;
    top = cam_top + 3;
    right = cam_left + 14;
    bottom = top + 8;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH)
        {
            cam_left = gObjectEvents[i].currentCoords.x;
            cam_top = gObjectEvents[i].currentCoords.y;
            if (left <= cam_left && cam_left <= right && top <= cam_top && cam_top <= bottom)
                AllowBerryTreeGrowth(gObjectEvents[i].trainerRange_berryTreeId);
        }
    }
}
