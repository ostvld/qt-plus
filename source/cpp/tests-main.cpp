
#include "CGeoUtilities.h"
#include "QTree.h"
#include "QMLTree/QMLTreeContext.h"
#include "QMLTree/QMLAnalyzer.h"

QString Vector3DString(const QVector3D& vec)
{
    return "<" + QString::number(vec.x(), 'f', 2) + ", " + QString::number(vec.y(), 'f', 2) + ", " + QString::number(vec.z(), 'f', 2) + ">";
}

QString GeoCoordinateString(const QGeoCoordinate& vec)
{
    return "<" + QString::number(vec.latitude(), 'f', 6) + ", " + QString::number(vec.longitude(), 'f', 6) + ", " + QString::number(vec.altitude(), 'f', 6) + ">";
}

int main()
{
    QGeoCoordinate Pos;
    QGeoCoordinate Ref;
    QVector3D vPosition;

    qDebug() << "GeoCoordinateToVector3D";
    qDebug() << "";

    Ref = QGeoCoordinate( 0.0, 0.0, 0.0);
    Pos = QGeoCoordinate(10.0, 0.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref  0.0,   0.0 and pos 10.0,   0.0 = " << Vector3DString(vPosition);

    Ref = QGeoCoordinate(20.0, 0.0, 0.0);
    Pos = QGeoCoordinate(30.0, 0.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref 20.0,   0.0 and pos 30.0,   0.0 = " << Vector3DString(vPosition);

    Ref = QGeoCoordinate(50.0, 0.0, 0.0);
    Pos = QGeoCoordinate(60.0, 0.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref 50.0,   0.0 and pos 60.0,   0.0 = " << Vector3DString(vPosition);

    Ref = QGeoCoordinate( 0.0,  0.0, 0.0);
    Pos = QGeoCoordinate( 0.0, 45.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref  0.0,   0.0 and pos  0.0,  45.0 = " << Vector3DString(vPosition);

    Ref = QGeoCoordinate( 0.0, 45.0, 0.0);
    Pos = QGeoCoordinate( 0.0, 90.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref  0.0,  45.0 and pos  0.0,  90.0 = " << Vector3DString(vPosition);

    Ref = QGeoCoordinate(50.0,  0.0, 0.0);
    Pos = QGeoCoordinate(50.1,  0.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref 50.0,   0.0 and pos 50.1,   0.0 = " << Vector3DString(vPosition);

    Ref = QGeoCoordinate(50.0, 45.0, 0.0);
    Pos = QGeoCoordinate(50.1, 45.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref 50.0,  45.0 and pos 50.1,  45.0 = " << Vector3DString(vPosition);

    Ref = QGeoCoordinate(50.0, 90.0, 0.0);
    Pos = QGeoCoordinate(50.1, 90.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref 50.0,  90.0 and pos 50.1,  90.0 = " << Vector3DString(vPosition);

    Ref = QGeoCoordinate(50.0, 135.0, 0.0);
    Pos = QGeoCoordinate(50.1, 135.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref 50.0, 135.0 and pos 50.1, 135.0 = " << Vector3DString(vPosition);

    Ref = QGeoCoordinate(50.0, 180.0, 0.0);
    Pos = QGeoCoordinate(50.1, 180.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref 50.0, 180.0 and pos 50.1, 180.0 = " << Vector3DString(vPosition);

    Ref = QGeoCoordinate(80.0,  0.0, 0.0);
    Pos = QGeoCoordinate(80.1,  0.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref 80.0,   0.0 and pos 80.1,   0.0 = " << Vector3DString(vPosition);

    Ref = QGeoCoordinate(80.0, 45.0, 0.0);
    Pos = QGeoCoordinate(80.1, 45.0, 0.0);
    vPosition = CGeoUtilities::getInstance()->GeoCoordinateToVector3D(Pos, Ref);
    qDebug() << "ref 80.0,  45.0 and pos 80.1,  45.0 = " << Vector3DString(vPosition);

    qDebug() << "";
    qDebug() << "Vector3DToGeoCoordinate";
    qDebug() << "";

    Ref = QGeoCoordinate(0.0, 0.0, 0.0);
    vPosition = QVector3D(0.0, -96264.0, 1100248.50);
    Pos = CGeoUtilities::getInstance()->Vector3DToGeoCoordinate(vPosition, Ref);
    qDebug() << "ref  0.0, 0.0 and pos 0.0, -96264.0, 1100248.50 = " << GeoCoordinateString(Pos);

    Ref = QGeoCoordinate(20.0, 0.0, 0.0);
    vPosition = QVector3D(0.0, -98819.0, 1101919.88);
    Pos = CGeoUtilities::getInstance()->Vector3DToGeoCoordinate(vPosition, Ref);
    qDebug() << "ref 20.0, 0.0 and pos 0.0, -98819.0, 1101919.88 = " << GeoCoordinateString(Pos);

    // QTree
    QTree<QString> tTree("Root");

    tTree.append("Item 10");
    tTree.append("Item 20");
    tTree.append("Item 30");
    tTree.append("Item 40");
    tTree.append("Item 50");
    tTree.append("Item 60");
    tTree.append("Item 70");
    tTree.append("Item 80");
    tTree.append("Item 90");

    tTree.getChildren()[0] << "Item 11";
    tTree.getChildren()[0] << "Item 12";
    tTree.getChildren()[0] << "Item 13";
    tTree.getChildren()[0] << "Item 14";
    tTree.getChildren()[0] << "Item 15";

    tTree.getChildren()[1] << "Item 21";
    tTree.getChildren()[1] << "Item 22";
    tTree.getChildren()[1] << "Item 23";
    tTree.getChildren()[1] << "Item 24";
    tTree.getChildren()[1] << "Item 25";

    qDebug() << "Item10 parent value = " << tTree.getChildren()[0].parent()->value();
    qDebug() << "Item20 parent value = " << tTree.getChildren()[1].parent()->value();
    qDebug() << "Item30 parent value = " << tTree.getChildren()[2].parent()->value();
    qDebug() << "Item40 parent value = " << tTree.getChildren()[3].parent()->value();
    qDebug() << "Item50 parent value = " << tTree.getChildren()[4].parent()->value();
    qDebug() << "Item60 parent value = " << tTree.getChildren()[5].parent()->value();
    qDebug() << "Item70 parent value = " << tTree.getChildren()[6].parent()->value();
    qDebug() << "Item80 parent value = " << tTree.getChildren()[7].parent()->value();
    qDebug() << "Item90 parent value = " << tTree.getChildren()[8].parent()->value();

    qDebug() << "Item11 parent value = " << tTree.getChildren()[0].getChildren()[0].parent()->value();
    qDebug() << "Item12 parent value = " << tTree.getChildren()[0].getChildren()[1].parent()->value();
    qDebug() << "Item13 parent value = " << tTree.getChildren()[0].getChildren()[2].parent()->value();
    qDebug() << "Item14 parent value = " << tTree.getChildren()[0].getChildren()[3].parent()->value();
    qDebug() << "Item15 parent value = " << tTree.getChildren()[0].getChildren()[4].parent()->value();

    qDebug() << "Item21 parent value = " << tTree.getChildren()[1].getChildren()[0].parent()->value();
    qDebug() << "Item22 parent value = " << tTree.getChildren()[1].getChildren()[1].parent()->value();
    qDebug() << "Item23 parent value = " << tTree.getChildren()[1].getChildren()[2].parent()->value();
    qDebug() << "Item24 parent value = " << tTree.getChildren()[1].getChildren()[3].parent()->value();
    qDebug() << "Item25 parent value = " << tTree.getChildren()[1].getChildren()[4].parent()->value();

    // tTree.assignParents();

    qDebug() << "";
    qDebug() << "--------------------------------------------------------------------";

    // QMLTree
    QString sInputFile = "D:/Work/SomeFile.qml";

    QMLTreeContext context(sInputFile);
    context.setIncludeImports(false);
    QMLTreeContext::EParseError error = context.parse();

    if (error == QMLTreeContext::peSuccess)
    {
        context.item().toXMLNode(&context, NULL).saveXMLToFile("Output.xml");

        QFile file("Output.qml");
        if (file.open(QFile::WriteOnly))
        {
            QTextStream stream(&file);
            context.item().toQML(stream, &context);
            file.close();
        }
    }

    QMLAnalyzer tAnalyzer;

    tAnalyzer.setFile(sInputFile);
    tAnalyzer.analyze(CXMLNode::load("CodingRules.xml"));

    qDebug() << "";
    qDebug() << "--------------------------------------------------------------------";

    foreach (QString sText, tAnalyzer.errors())
    {
        qDebug() << sText;
    }

    /*
    qDebug() << "";
    qDebug() << "--------------------------------------------------------------------";

    // QMLAnalyzer
    QMLAnalyzer tAnalyzer;

    tAnalyzer.setFolder("D:/Work/SomeFolder");
    tAnalyzer.analyze(CXMLNode::load("CodingRules.xml"));

    qDebug() << "";
    qDebug() << "--------------------------------------------------------------------";

    foreach (QString sText, tAnalyzer.errors())
    {
        qDebug() << sText;
    }
    */

    return 0;
}
