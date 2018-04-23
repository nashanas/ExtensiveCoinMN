// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("extn:e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("extn:e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("extn:e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm?label=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm"));
    QVERIFY(rv.label == QString("Some Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("extn:e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("extn:e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("extn:e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm?amount=100&label=Some Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Some Example"));

    uri.setUrl(QString("extn:e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm?message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("extn://e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm?message=Some Example Address", &rv));
    QVERIFY(rv.address == QString("e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("extn:e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm?req-message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("extn:e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm?amount=1,000&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("extn:e8QZGSZxsgPfV3JL51xiJ5XMJJ1W1AzTKm?amount=1,000.0&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
